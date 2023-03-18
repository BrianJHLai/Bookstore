#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <algorithm>
using std::string;

#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

struct Purchase {
	int copies;
	float price;
	int year;
	int total_days; //The number of days into a year E.g. Feb 15 = 46
};

class Member {
 	private:
  	//Attributes
	string name;
	string address;
	std::unordered_map<string, std::vector<Purchase>> books_bought;
	std::vector<string> books_returned;

  public:
  	//Constructor
	Member(string n, string a) {
		name = n;
		address = a;
	}

	//Setters
	void changeName(string n) {
		name = n;
	}

	void changeAddress(string a) {
		address = a;
	}

	void memBuyBook(string t, int c, float p, int yr, int td) {

		struct Purchase pur = {c, p, yr, td};

		if (books_bought.find(t) != books_bought.end()) {
			books_bought.find(t)->second.push_back(pur);
		}
		else {
			std::vector<Purchase> v {pur};
			books_bought[t] = v;
		}
	}

	std::pair<int,float> returnBook(string t, int c) { //

		int stock = 0;
		float money = 0;

		if (c >= books_bought[t].back().copies) {
			stock = books_bought[t].back().copies;
			money = books_bought[t].back().copies * books_bought[t].back().price;
			books_bought[t].pop_back();
			if (books_bought[t].empty()) {
				books_bought.erase(t);
			}
		}
		else {
			stock = c;
			money = c * books_bought[t].back().price;
			books_bought[t].back().copies -= c;
		}

		std::vector<string>::iterator it;
		it = find(books_returned.begin(), books_returned.end(), t);

		if (it == books_returned.end()) {
			books_returned.push_back(t);
		}

		std::pair<int,float> p (stock, money);
		
		return p;
	}

	//Getters
	string getName() {
		return name;
	}

	string getAddress() {
		return address;
	}

	int getBoughtNum() {
		return books_bought.size();
	}

	int getReturnedNum() {
		return books_returned.size();
	}

	void getBooksBought() {
		for (auto i: books_bought) 
			std::cout << i.first << std::endl;

		std::cout << std::endl;
	}

	void getBooksReturned() {
		for (int i = 0; i < books_returned.size(); i++) {
			std::cout << books_returned[i] << std::endl;
		}

		std::cout << std::endl;
	}

	//Other
	bool didBuyBook(string t) {
		if (books_bought.find(t) != books_bought.end()) {
			return true;
		}

		return false;
	}

	bool withinThirtyDays(string t, int yr, int td) {
		if (didBuyBook(t)) {
			int yr_diff = yr - books_bought[t].back().year;
			int td_diff = td - books_bought[t].back().total_days;
			if (abs(yr_diff * 365 - td_diff) <= 30) {
				return true;
			}
		}

		return false;
	}
};

void nonEmptyInput(string& input);

void viewMembers(std::vector<Member>& mems);

void viewBooksBought(std::vector<Member>& mems);

void viewBooksReturned(std::vector<Member>& mems);

void addMember(std::vector<Member>& mems);

void removeMember(std::vector<Member>& mems);

void modifyMember(std::vector<Member>& mems);

#endif