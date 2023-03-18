#include "employee.h"


//Prints out a list of every employee's name, address, position, and salary
void viewEmployees(std::vector<Employee>& emps) {
	if (emps.size() == 0) {
		std::cout << "The bookstore currently has no employees.\n" << std::endl;
		return;
	}

	for (int i = 0; i < emps.size(); i++) {
		std::cout << "Name: " << emps[i].getName() << "; Address: " << emps[i].getAddress() 
		<< "; Position: " << emps[i].getPosition() << "; Salary: $" << emps[i].getSalary() << std::endl;
	}

	std::cout << std::endl;
}

//Add a new employee record
void addEmployee(std::vector<Employee>& emps) {
	std::cout << "Please input the name of the employee that you wish to add a record for: ";
	string name;
	nonEmptyInput(name);

	//Make sure the inputted name isn't that of an existing employee
	for (int i = 0; i < emps.size(); i++) {
		if (emps[i].getName() == name) {
			std::cout << "This person is already employed!" << std::endl;
			return;
		}
	}

	std::cout << "Please input the address of the employee that you wish to add: ";
	string address;
	nonEmptyInput(address);

	std::cout << "Please input the position of the employee that you wish to add: ";
	string position;
	nonEmptyInput(position);

	std::cout << "Please input the salary of the employee that you wish to add: ";
	float salary = getFloat();

	Employee e(name, address, position, salary);

	emps.push_back(e);

	std::cout << name << "'s employee record has been added.\n" << std::endl; //If name ends in s?
}

//Delete an employee record
void removeEmployee(std::vector<Employee>& emps) {
	if (emps.size() == 0) {
		std::cout << "The bookstore currently has no employees.\n" << std::endl;
		return;
	}

	std::cout << "Please input the name of the employee that you wish to remove: ";
	string name;
	nonEmptyInput(name);

	//Find the employee, and remove them from the database
	for (int i = 0; i < emps.size(); i++) {
		if (emps[i].getName() == name) {
			emps.erase(emps.begin() + i);
			std::cout << name << "'s employee record has been removed.\n" << std::endl; //s?
			return;
		}
	}

	//Occurs only if the name given was not a current employee's name
	std::cout << "There is currently no employee named " << name << " working here!\n" << std::endl;
}

//Function to specifically change an employee's name
void modifyName(Employee& emp) {
	std::cout << "Please input the employee's new name: ";
	string name;
	nonEmptyInput(name);

	string old_name = emp.getName();

	emp.changeName(name);

	std::cout << old_name << "'s new name is " << name << ".\n" << std::endl;
}

//Function to specifically change an employee's address
void modifyAddress(Employee& emp) {
	std::cout << "Please input the employee's new address: ";
	string address;
	nonEmptyInput(address);

	emp.changeAddress(address);

	std::cout << emp.getName() << "'s new address is " << address << ".\n" << std::endl;
}

//Function to specifically change an employee's position
void modifyPosition(Employee& emp) {
	std::cout << "Please input the employee's new position: ";
	string position;
	nonEmptyInput(position);

	emp.changePosition(position);

	std::cout << emp.getName() << "'s new position is " << position << ".\n" << std::endl;
}

//Function to specifically change an employee's salary
void modifySalary(Employee& emp) {
	std::cout << "Please input the employee's new salary: ";
	float salary = getFloat();

	emp.changeSalary(salary);

	std::cout << emp.getName() << "'s new salary is $" << salary << ".\n" << std::endl;
}

//Modify an employee record
void modifyEmployee(std::vector<Employee>& emps) {
	if (emps.size() == 0) {
		std::cout << "The bookstore currently has no employees.\n" << std::endl;
		return;
	}
	
	string option;

	std::cout << "Please input the name of the employee whose record you wish to modify: ";
	string name;
	nonEmptyInput(name);

	//Make sure the inputted name is that of an existing employee
	int location = -1;

	for (int i = 0; i < emps.size(); i++) {
		if (emps[i].getName() == name) {
			location = i;
			break;
		}
	}

	if (location == -1) {
		std::cout << name << " is currently not employed at the bookstore!\n" << std::endl;
		return;
	}

	while (true) {
		std::cout << "What do you wish to modify?" << std::endl;
		std::cout << "1. Employee name" << std::endl;
		std::cout << "2. Employee address" << std::endl;
		std::cout << "3. Employee position" << std::endl;
		std::cout << "4. Employee salary" << std::endl;
		std::cout << "5. Return to Employee Database menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		//Make sure that the user inputs a single digit
		if (option.length() > 1 || !isdigit(option[0])) { 
			std::cout << "Please type a number from 1 to 5.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				modifyName(emps[location]);
				break;
			case 2:
				modifyAddress(emps[location]);
				break;
			case 3:
				modifyPosition(emps[location]);
				break;
			case 4:
				modifySalary(emps[location]);
				break;
			case 5:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 5.\n" << std::endl;
				break;
		}
	}

	std::cout << "Modification of " << name << "'s employee record is complete.\n" << std::endl; //s?
}