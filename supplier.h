#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
//#include <algorithm>
using std::string;

#ifndef SUP_H_INCLUDED
#define SUP_H_INCLUDED

class Supplier {
  private:
  	//Attributes
	string name;
	string address;
	std::vector<string> books;

  public:
  	//Constructor
	Supplier(string n, string a) {
		name = n;
		address = a;
	}

	//Setters
	void addBook(string t) { //Name
		books.push_back(t);
	}

	void checkAndAdd(string t) { //Name
		for (int i = 0; i < books.size(); i++) {
			if (books[i] == t) {
				return;
			}
		}

		books.push_back(t);
	}

	void changeName(string n) {
		name = n;
	}

	void changeAddress(string a) {
		address = a;
	}

	//Getters
	string getName() {
		return name;
	}

	string getAddress() {
		return address;
	}

	int getBooksNum() { //Name
		return books.size();
	}

	void getBooks() { //Name
		for (int i = 0; i < books.size(); i++) {
			std::cout << books[i] << std::endl;
		}
	}
};



void viewSuppliers(std::vector<Supplier>& sups);

void viewSupplierBooks(std::vector<Supplier>& sups); //name

void addSupplier(std::vector<Supplier>& sups);

void removeSupplier(std::vector<Supplier>& sups);

void modifySupplier(std::vector<Supplier>& sups);

#endif