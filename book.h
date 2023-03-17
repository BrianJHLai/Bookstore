#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <iomanip>
//#include <algorithm>
using std::string;

#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

//If making another cpp file, put function names in here so that main.cpp can call those functions


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

//class Sales;



int getInt();

float getFloat();

void viewBooks(std::vector<Book>& books);

void addBook(std::vector<Book>& books, std::vector<Supplier>& sups, float& loss); //std::vector<Supplier>& sups

void sellBook(std::vector<Book>& books, std::vector<Member>& mems, float& profit); //std::vector<Sales>& sal

void managePrice(std::vector<Book>& books);

//void bookReturn(std::vector<Member>& mems, std::vector<Book>& books, float& profit);

#endif