#include "member.h"


//View list of members
void viewMembers(std::vector<Member>& mems) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	for (int i = 0; i < mems.size(); i++) {
		std::cout << "Name: " << mems[i].getName() << "; Address: " 
		<< mems[i].getAddress() << std::endl;
	}

	std::cout << std::endl;
}

//View a list of books bought by a member
void viewBooksBought(std::vector<Member>& mems) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	std::cout << "PLease input the name of the member whose list of books bought "
	<< "that you wish to view: ";
	string name;
	nonEmptyInput(name);

	//Find the member
	int location = -1;
	for (int i = 0; i < mems.size(); i++) {
		if (mems[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location != -1) {
		if (mems[location].getBoughtNum() == 0) {
			std::cout << name << " does not have any books that they have bought " 
			<< "from the bookstore.\n" << std::endl;
			return;
		}

		mems[location].getBooksBought();
	}
	else {
		std::cout << "The bookstore has no records of a member by the name of " << name
		<< "!\n" << std::endl;
	}
}

//View a list of books returned by a member
void viewBooksReturned(std::vector<Member>& mems) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	;std::cout << "PLease input the name of the member whose list of books returned "
	<< "that you wish to view: ";
	string name;
	nonEmptyInput(name);

	//Find the member
	int location = -1;
	for (int i = 0; i < mems.size(); i++) {
		if (mems[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location != -1) {
		if (mems[location].getReturnedNum() == 0) {
			std::cout << name << " has yet to return any books to the bookstore.\n" << std::endl;
			return;
		}

		mems[location].getBooksReturned();
	}
	else {
		std::cout << "The bookstore has no records of a member by the name of " << name
		<< "!\n" << std::endl;
	}
}

//Add a new member record
void addMember(std::vector<Member>& mems) {
	std::cout << "Please input the name of the member you wish to add: ";
	string name;
	nonEmptyInput(name);

	//Check if there is already a record of the member
	for (int i = 0; i < mems.size(); i++) {
		if (mems[i].getName() == name) {
			std::cout << "The bookstore already has a record for " << name << "!\n" <<std::endl;
			return;
		}
	}

	std::cout << "Please input the address of the member that you wish to add: ";
	string address;
	nonEmptyInput(address);

	Member m(name, address);

	mems.push_back(m);

	std::cout << name << "'s member record has been added.\n" << std::endl;
}

//Remove a member record
void removeMember(std::vector<Member>& mems) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	std::cout << "Please input the name of the member you wish to remove: ";
	string name;
	nonEmptyInput(name);

	//Find the record of the member, and remove them
	for (int i = 0; i < mems.size(); i++) {
		if (mems[i].getName() == name) {
			mems.erase(mems.begin() + i);
			std::cout << name << "'s member record has been removed.\n" <<std::endl;
			return;
		}
	}

	//Occurs only if the name given was not a current member's name
	std::cout << "The bookstore has no records of a member by the name of " << name 
	<< "!\n" << std::endl;
}

//Modify a member's name
void modifyName(Member& mem) {
	std::cout << "Please input the member's new name: ";
	string name;
	nonEmptyInput(name);

	string old_name = mem.getName();

	mem.changeName(name);

	std::cout << old_name << "'s new name is " << name << ".\n" << std::endl;
}

//Modify a member's address
void modifyAddress(Member& mem) {
	std::cout << "Please input the member's new address: ";
	string address;
	nonEmptyInput(address);

	mem.changeAddress(address);

	std::cout << mem.getName() << "'s new address is " << address << ".\n" << std::endl;
}

//Modify a member record
void modifyMember(std::vector<Member>& mems) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	string option;

	std::cout << "Please input the name of the member whose record you wish to modify: ";
	string name;
	nonEmptyInput(name);

	//Find the member
	int location = -1;
	for (int i = 0; i < mems.size(); i++) {
		if (mems[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location == -1) {
		std::cout << "The bookstore has no records of a member by the name of " << name 
		<< "!\n" << std::endl;
		return;
	}

	while (true) {
		std::cout << "What do you wish to modify?" << std::endl;
		std::cout << "1. Member name" << std::endl;
		std::cout << "2. Member address" << std::endl;
		std::cout << "3. Return to Member Database menu" << std::endl;
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
				modifyName(mems[location]);
				break;
			case 2:
				modifyAddress(mems[location]);
				break;
			case 3:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 3.\n" << std::endl;
				break;
		}
	}

	std::cout << "Modification of " << name << "'s member record is complete.\n" << std::endl;
}
