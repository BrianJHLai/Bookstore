#include "book.h"
#include "supplier.h"
#include "member.h"
//#include <algorithm> //std::find

//Round doubles to 2 decimals

//Prints out a list of every book's title, price, and stock
void viewBooks(std::vector<Book>& books) {
	if (books.size() == 0) {
		std::cout << "The bookstore currently does not stock any books.\n" << std::endl;
		return;
	}

	for (int i = 0; i < books.size(); i++) {
		std::cout << "Title: " << books[i].getTitle() << "; Price: $" << std::fixed 
		<< std::setprecision(2) << books[i].getPrice() << "; Stock: " << books[i].getStock() << std::endl;
	}

	std::cout << std::endl;
}

//Add a new book to the store, or add more of a book to the store
void addBook(std::vector<Book>& books, std::vector<Supplier>& sups, float& loss) {
	if (sups.size() == 0) {
		std::cout << "The bookstore cannot stock books without having any suppliers." << std::endl;
		std::cout << "Please first go to the suppliers database and add at least one supplier "
		<< "to order new books.\n" << std::endl;
		return;
	}
				
	std::cout << "Please input the title of the book that you wish to add: ";
	string title;
	std::getline(std::cin, title);
	std::cout << std::endl;

	if (title.empty()) {
		while (title.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, title);
			std::cout << std::endl;
		}
	}

	//Supplier who sells the book //Must exist in supplier db
	std::cout << "Please input the name of the supplier whose list of books supplied "
	<< "that you wish to view: ";
	string supplier;
	std::getline(std::cin, supplier);
	std::cout << std::endl;

	if (supplier.empty()) {
		while (supplier.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, supplier);
			std::cout << std::endl;
		}
	}

	//Find the supplier
	int sup_location = -1;
	for (int i = 0; i < sups.size(); i++) {
		if (sups[i].getName() == supplier) {
			sup_location = i;
			break;
		}
	}

	if (sup_location == -1) {
		std::cout << "The bookstore has no records of a supplier by the name of " << supplier 
		<< "!\n" << std::endl;
		return;
	}

	std::cout << "Please input the cost of a copy of the book that the supplier is charging: ";
	int cost = getFloat();

	std::cout << "Please input how many of the book that you wish to add: ";
	int stock = getInt();

	//Finding the specific book
	int location = -1;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			location = i;
			break;
		}
	}
				
	if (location != -1) {
		books[location].changeStock(stock);

		//Check if this supplier has ever supplied this book before
		//If not, add the title to the supplier's list of books supplied
		sups[sup_location].checkAndAdd(title);

		std::cout << "New copies of " << title << " have been added.\n" << std::endl;
	}
	else {
		std::cout << "Please input the price you wish to set for each book: ";
		float price = getFloat();

		Book b(title, price, stock);

		books.push_back(b);

		//Add the title to the supplier's list of books supplied
		sups[sup_location].addBook(title);

		std::cout << "The store now stocks copies of " << title << ".\n" << std::endl;
	}

	loss += stock * cost;
}

//Sell books //Should contemplate moving when stock == 0
void sellBook(std::vector<Book>& books, std::vector<Member>& mems, float& profit) {
	if (books.size() == 0) {
		std::cout << "The bookstore currently does not stock any books.\n" << std::endl;
		return;
	}
				
	std::cout << "Please input the title of the book that you wish to sell: ";
	string title;
	std::getline(std::cin, title);
	std::cout << std::endl;

	if (title.empty()) {
		while (title.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, title);
			std::cout << std::endl;
		}
	}

	std::cout << "Please input how many of the book that you wish to sell: ";
	int stock = getInt();

	//Finding the specific book
	int location = -1;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			location = i;
			break;
		}
	}

	//Either sell the book if it is in stock, or alert that it is out of stock
	if (location != -1) {
		//Check if the customer is a member
		std::cout << "Please input the name of the customer, in case they are a member: ";
		string customer;
		std::getline(std::cin, customer);
		std::cout << std::endl;

		if (customer.empty()) {
			while (customer.empty()) {
				std::cout << "Please give a non-empty input: "; //
				std::getline(std::cin, customer);
				std::cout << std::endl;
			}
		}

		//Looking for the customer's name in the member database
		for (int i = 0; i < mems.size(); i++) {
			if (mems[i].getName() == customer) {
				mems[i].memBuyBook(title);
				std::cout << "The customer was a member." << std::endl;
				std::cout << "The book they just bought has been added to their book list.\n" << std::endl; //
				break;
			}
		}

		//Selling of the book(s)
		if (stock >= books[location].getStock()) {
			profit += books[location].getStock() * books[location].getPrice();

			books[location].changeStock(books[location].getStock() * -1);

			std::cout << "All remaining copies of " << title << " have been sold.\n" << std::endl;
		}
		else if (stock < books[location].getStock()) {
			profit += stock * books[location].getPrice();

			books[location].changeStock(stock * -1);

			if (stock == 1) {
				std::cout << stock << " copy of " << title <<" has been sold.\n" << std::endl;
			}
			else {
				std::cout << stock << " copies of " << title <<" have been sold.\n" << std::endl;
			}
		}
		else {
			std::cout << title << " is out of stock!\n" << std::endl;
		}
	}
	else {
		std::cout << title << " is not stocked by the store!\n" << std::endl;
	}
}

//Change a book's price //Change func name and (use) to general modifyBook?
void managePrice(std::vector<Book>& books) {
	if (books.size() == 0) {
		std::cout << "The bookstore currently does not stock any books.\n" << std::endl;
		return;
	}
				
	std::cout << "Please input the title of the book that you wish to modify the price for: ";
	string title;
	std::getline(std::cin, title);
	std::cout << std::endl;

	if (title.empty()) {
		while (title.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, title);
			std::cout << std::endl;
		}
	}

	//Finding the specific book
	int location = -1;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			location = i;
			break;
		}
	}

	if (location != -1) {
		std::cout << "Please input the new price you wish to set for each book: ";
		float price = getFloat();

		books[location].changePrice(price);

		std::cout << "The price for a copy of " << title << " has been changed to $" << std::fixed
		<< std::setprecision(2) << price << ".\n" << std::endl;
	}
	else {
		std::cout << title << " is not stocked by the store!\n" << std::endl;
	}
}
/*
//Recieve a returned book from a member
void bookReturn(std::vector<Member>& mems, std::vector<Book>& books, float& profit) {
	if (mems.size() == 0) {
		std::cout << "The bookstore currently does not have any members.\n" << std::endl;
		return;
	}

	std::cout << "Please input the name of the member who wished to return a book: ";
	string name = nonEmptyInput(name);

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

	std::cout << "Please input the title of the book that the member wishes to return: ";
	string title = nonEmptyInput(title);

	//Check if the bookstore stocks the given title
	int book_location = -1;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			book_location = i;
			break;
		}
	}

	if (mems[location].didBuyBook(title) && book_location != -1) {
		std::cout << "Please input the number of copies of the book that the member wishes to return: ";
		int copies = getInt();

		mems[location].returnBook(title, copies);

		profit -= copies * books[book_location].getPrice();

		if (copies == 1) {
			std::cout << "The member has returned a copy of " << title << ".\n"<< std::endl;
		}
		else {
			std::cout << "The member has returned " << copies << " copies of " << title << ".\n"<< std::endl;
		}
	}
	else {
		std::cout << "The member cannot return a book that is not in their most recent purchase, "
		<< "nor can they return a book that was not bought from this bookstore.\n" << std::endl;
	}

}
*/

//Reference for previous version of returnBook
/*
	//Check if the member bought the book from the bookstore
	if (mems[location].didBuyBook(title)) {
		mems[location].returnBook(title);
		std::cout << "The member has returned a copy of " << title << ".\n"<< std::endl;
	}
	else {
		std::cout << "The member cannot return a book that is not in their possession, nor can "
		<< "they return a book that was not bought from this bookstore!\n" << std::endl;
	}
*/
//sellBook