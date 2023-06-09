#include <string>
#include <iostream>
#include <vector>
#include <ctype.h> //isdigit
#include <cmath>
#include <iomanip> //formating
#include <chrono> //clock
#include <ctime>  //clock
using std::string;

#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED


class Book {
  private:
	//Attributes
	string title;
	float price;
	int stock;

  public:
	//Constructors
	Book(string t, float p, int s) {
		title = t;
		price = p;
		stock = s;
	}

	//Setters
	void changeStock(int s) {
		stock += s;
	}

	void changePrice(float p) {
		price = p;
	}

	//Getters
	string getTitle() {
		return title;
	}

	float getPrice() {
		return price;
	}

	int getStock() {
		return stock;
	}

};

class Supplier;

class Member;

void nonEmptyInput(string& input);

int getInt();

float getFloat();

int getTotalDays(int mon, int date);

void viewBooks(std::vector<Book>& books);

void addBook(std::vector<Book>& books, std::vector<Supplier>& sups, float& loss);

void sellBook(std::vector<Book>& books, std::vector<Member>& mems, float& profit);

void managePrice(std::vector<Book>& books);

void bookReturn(std::vector<Member>& mems, std::vector<Book>& books, float& profit);

#endif