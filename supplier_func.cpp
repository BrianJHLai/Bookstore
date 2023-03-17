#include "supplier.h"

//

//View all supplier records
void viewSuppliers(std::vector<Supplier>& sups) {
	if (sups.size() == 0) {
		std::cout << "The bookstore currently has no suppliers.\n" <<std::endl;
		return;
	}

	for (int i = 0; i < sups.size(); i++) {
		std::cout << "Name: " << sups[i].getName() << "; Address: " << sups[i].getAddress() 
		<< "; Number of books supplied: " << sups[i].getBooksNum() << std::endl;
	}

	std::cout << std::endl;
}

//View a supplier's list of books supplied
void viewSupplierBooks(std::vector<Supplier>& sups) { //Name
	if (sups.size() == 0) {
		std::cout << "The bookstore currently has no suppliers.\n" <<std::endl;
		return;
	}

	std::cout << "Please input the name of the supplier whose list of books supplied "
	<< "that you wish to view: ";
	string name;
	std::getline(std::cin, name);
	std::cout << std::endl;

	if (name.empty()) {
		while (name.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, name);
			std::cout << std::endl;
		}
	}

	//Find the supplier
	int location = -1;
	for (int i = 0; i < sups.size(); i++) {
		if (sups[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location != -1) {
		if (sups[location].getBooksNum() == 0) {
			std::cout << name << " has yet to supply any books to the bookstore.\n" << std::endl;
			return;
		}

		sups[location].getBooks();

		std::cout << std::endl;
	}
	else {
		std::cout << "The bookstore has no records of a supplier by the name of " << name 
		<< "!\n" << std::endl;
		return;
	}
}

//Add a new supplier record
void addSupplier(std::vector<Supplier>& sups) {
	std::cout << "Please input the name of the supplier you wish to add: ";
	string name;
	std::getline(std::cin, name);
	std::cout << std::endl;

	if (name.empty()) {
		while (name.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, name);
			std::cout << std::endl;
		}
	}

	//Check if there is already a record of the supplier
	for (int i = 0; i < sups.size(); i++) {
		if (sups[i].getName() == name) {
			std::cout << "The bookstore already has a record for " << name << "!\n" <<std::endl;
			return;
		}
	}

	std::cout << "Please input the address of the supplier that you wish to add: ";
	string address;
	std::getline(std::cin, address);
	std::cout << std::endl;

	if (address.empty()) {
		while (address.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, address);
			std::cout << std::endl;
		}
	}

	Supplier s(name, address);

	sups.push_back(s);

	std::cout << name << "'s supplier record has been added.\n" << std::endl;
}

//Remove a supplier record
void removeSupplier(std::vector<Supplier>& sups) {
	if (sups.size() == 0) {
		std::cout << "The bookstore currently has no suppliers.\n" <<std::endl;
		return;
	}

	std::cout << "Please input the name of the supplier you wish to remove: ";
	string name;
	std::getline(std::cin, name);
	std::cout << std::endl;

	if (name.empty()) {
		while (name.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, name);
			std::cout << std::endl;
		}
	}

	//Find the record of the supplier, and remove it
	for (int i = 0; i < sups.size(); i++) {
		if (sups[i].getName() == name) {
			sups.erase(sups.begin() + i);
			std::cout << name << "'s supplier record has been removed.\n" <<std::endl;
			return;
		}
	}

	//Occurs only if the name given was not a current supplier's name
	std::cout << "The bookstore has no records of a supplier by the name of " << name 
	<< "!\n" << std::endl;
}

//
void modifyName(Supplier& sup) {
	std::cout << "Please input the supplier's new name: ";
	string name;
	std::getline(std::cin, name);
	std::cout << std::endl;

	if (name.empty()) {
		while (name.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, name);
			std::cout << std::endl;
		}
	}

	string old_name = sup.getName();

	sup.changeName(name);

	std::cout << old_name << "'s new name is " << name << ".\n" << std::endl;
}

//
void modifyAddress(Supplier& sup) {
	std::cout << "Please input the supplier's new address': ";
	string address;
	std::getline(std::cin, address);
	std::cout << std::endl;

	if (address.empty()) {
		while (address.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, address);
			std::cout << std::endl;
		}
	}

	sup.changeAddress(address);

	std::cout << sup.getName() << "'s new address is " << address << ".\n" << std::endl;
}

//Modify a supplier's record
void modifySupplier(std::vector<Supplier>& sups) {
	if (sups.size() == 0) {
		std::cout << "The bookstore currently has no suppliers.\n" <<std::endl;
		return;
	}

	string option;

	std::cout << "Please input the name of the supplier whose record you wish to modify: ";
	string name;
	std::getline(std::cin, name);
	std::cout << std::endl;

	if (name.empty()) {
		while (name.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, name);
			std::cout << std::endl;
		}
	}

	//Find the supplier
	int location = -1;

	for (int i = 0; i < sups.size(); i++) {
		if (sups[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location == -1) {
		std::cout << "The bookstore has no records of a supplier by the name of " << name 
		<< "!\n" << std::endl;
		return;
	}

	while (true) {
		std::cout << "What do you wish to modify?" << std::endl;
		std::cout << "1. Supplier name" << std::endl;
		std::cout << "2. Supplier address" << std::endl;
		std::cout << "3. Return to Supplier Database menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		//Make sure that the user inputs a single digit
		if (option.length() > 1 || !isdigit(option[0])) { 
			std::cout << "Please type a number from 1 to 3.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				modifyName(sups[location]);
				break;
			case 2:
				modifyAddress(sups[location]);
				break;
			case 3:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 3.\n" << std::endl;
				break;
		}
	}

	std::cout << "Modification of " << name << "'s supplier record is complete.\n" << std::endl;
}