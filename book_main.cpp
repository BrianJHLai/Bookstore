#include "book.h"
#include "employee.h"
#include "supplier.h"
#include "member.h"
//#include "sales.h"
#include <stdlib.h>


//
void manage_store(std::vector<Book>& books, std::vector<Supplier>& sups, std::vector<Member>& mems,
	float& profit, float& loss) {
	string option;

	while (true) {
		std::cout << "1. View book list" << std::endl;
		std::cout << "2. Buy books from supplier" << std::endl;
		std::cout << "3. Sell books to customers" << std::endl;
		std::cout << "4. Manage book prices" << std::endl;
		//std::cout << "5. Receive a returned book" << std::endl;
		std::cout << "6. Return to main menu" << std::endl;
		//std::cout << "NOTE: Books may not be returned if any purchase is made after!" << std::endl;
		//std::cout << "Additionally, only members may return books, and only for those that they "
		//<< "have bought as a member." << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		//Make sure that the user inputs a single digit
		if (option.length() > 1 || !isdigit(option[0])) { 
			std::cout << "Please type a number from 1 to 6.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				viewBooks(books);
				break;
			case 2:
				addBook(books, sups, loss);
				break;
			case 3:
				sellBook(books, mems, profit);
				break;
			case 4:
				managePrice(books);
				break;
			//case 5:
				//bookReturn(mems, books, profit);
				//break;
			case 6:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 6.\n" << std::endl;
				break;
		}
	}
}

void employee_db(std::vector<Employee>& emps) {
	string option;

	while (true) {
		std::cout << "1. View employee records" << std::endl;
		std::cout << "2. Add employee record" << std::endl;
		std::cout << "3. Remove employee record" << std::endl;
		std::cout << "4. Modify employee record" << std::endl;
		std::cout << "5. Return to main menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		if (option.length() > 1 || !isdigit(option[0])) {
			std::cout << "Please type a number from 1 to 5.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				viewEmployees(emps);
				break;
			case 2:
				addEmployee(emps);
				break;
			case 3:
				removeEmployee(emps);
				break;
			case 4:
				modifyEmployee(emps);
				break;
			case 5:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 5.\n" << std::endl;
				break;
		}
	}
}

void supplier_db(std::vector<Supplier>& sups) {
	string option;

	while (true) {
		std::cout << "1. View supplier records" << std::endl;
		std::cout << "2. View a supplier's list of books supplied" << std::endl;
		std::cout << "3. Add supplier record" << std::endl;
		std::cout << "4. Remove supplier record" << std::endl;
		std::cout << "5. Modify supplier record" << std::endl;
		std::cout << "6. Return to main menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		if (option.length() > 1 || !isdigit(option[0])) {
			std::cout << "Please type a number from 1 to 6.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				viewSuppliers(sups);
				break;
			case 2:
				viewSupplierBooks(sups); //name
				break;
			case 3:
				addSupplier(sups);
				break;
			case 4:
				removeSupplier(sups);
				break;
			case 5:
				modifySupplier(sups);
				break;
			case 6:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 6.\n" << std::endl;
				break;
		}
	}
}

void member_db(std::vector<Member>& mems) {
	string option;

	while (true) {
		std::cout << "1. View member records" << std::endl;
		std::cout << "2. View list of books bought by a member" << std::endl;
		//std::cout << "3. View member records" << std::endl;
		std::cout << "4. Add member record" << std::endl;
		std::cout << "5. Remove member record" << std::endl;
		std::cout << "6. Modify member record" << std::endl;
		std::cout << "7. Return to main menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		if (option.length() > 1 || !isdigit(option[0])) {
			std::cout << "Please type a number from 1 to 7.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				viewMembers(mems);
				break;
			case 2:
				viewBooksBought(mems);
				break;
			//case 3:
				//viewBooksReturned(mems);
				//break;
			case 4:
				addMember(mems);
				break;
			case 5:
				removeMember(mems);
				break;
			case 6:
				modifyMember(mems);
				break;
			///case 7:
				//bookReturn(mems, books, profit);
				//break;
			case 7:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 7.\n" << std::endl;
				break;
		}
	}
}

void sales_records(float& profit, float& loss) {
	string option;

	while (true) {
		//std::cout << "1. See records for books sold" << std::endl;
		//std::cout << "2. See records for profit made" << std::endl;
		//std::cout << "3. See records for losses made" << std::endl;
		std::cout << "1. See total profits" << std::endl;
		std::cout << "2. See total losses" << std::endl;
		std::cout << "3. See total books sold" << std::endl;
		std::cout << "4. See total books bought" << std::endl;
		std::cout << "5. Return to main menu" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		if (option.length() > 1 || !isdigit(option[0])) {
			std::cout << "Please type a number from 1 to 5.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				std::cout << "Total profits: $" << std::fixed << std::setprecision(2) 
				<< profit << "\n" << std::endl;
				break;
			case 2:
				std::cout << "Total losses: $" << std::fixed << std::setprecision(2) 
				<< loss << "\n" << std::endl;
				break;
			case 3:
				;
				break;
			case 4:
				;
				break;
			case 5:
				return;
			default:
				std::cout << "Invalid option. Please type a number from 1 to 5.\n" << std::endl;
				break;
		}
	}
}

void main_menu(std::vector<Book>& books, std::vector<Employee>& emps, std::vector<Supplier>& sups, 
	std::vector<Member>& mems, float& profit, float& loss) {
	string option;

	while (true) {
		std::cout << "1. Manage the bookstore" << std::endl;
		std::cout << "2. Employee Database" << std::endl;
		std::cout << "3. Supplier Database" << std::endl;
		std::cout << "4. Member Database" << std::endl;
		std::cout << "5. Sales Records" << std::endl;
		std::cout << "6. Quit" << std::endl;
		std::cout << "Please select an option: ";
		std::getline(std::cin, option);
		std::cout << std::endl;

		if (option.length() > 1 || !isdigit(option[0])) {
			std::cout << "Please type a number from 1 to 6.\n" << std::endl;
			continue;
		}

		switch (stoi(option)) {
			case 1:
				manage_store(books, sups, mems, profit, loss);
				break;
			case 2:
				employee_db(emps);
				break;
			case 3:
				supplier_db(sups);
				break;
			case 4:
				member_db(mems);
				break;
			case 5:
				sales_records(profit, loss);
				break;
			case 6:
				return; //exit();
			default:
				std::cout << "Invalid option. Please type a number from 1 to 6.\n" << std::endl;
				break;
		}
	}
}


int main(int argc, char const *argv[])
{
	std::cout << "Welcome to the bookstore" << std::endl << std::endl;

	//Setup databases and records
	std::vector<Book> book_list;
	std::vector<Employee> employee_list;
	std::vector<Supplier> supplier_list;
	std::vector<Member> member_list;
	//std::vector<Sales> sales_list;
	//int books_bought = 0;
	//int books_sokd;= 0;
	float profit = 0; 
	float loss = 0;

	main_menu(book_list, employee_list, supplier_list, member_list, profit, loss);

	std::cout << "Goodbye!" << std::endl;

	return 0;
}