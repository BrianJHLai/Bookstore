#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <unordered_map>
//#include <algorithm>
using std::string;

#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

class Member {
  private:
  	//Attributes
	string name;
	string address;
	std::vector<string> books_bought; 
	//unordered_map<string, std::vector<pair<int, float>>> books_bought;
	//unordered_map<string, pair<int, float>> books_bought;
		//Unordered map key: title, value: <stock, total price>; Returns accepted if no other purchase made after
		//If same book purchased, erase previous key-value pair and add new one
	//std::vector<string> books_returned;

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

	void memBuyBook(string t) {
		books_bought.push_back(t);
	}
/*
	void returnBook(string t, int c) {
		
		//for (int i = 0; i < books_bought.size(); i++) {
			//if (books_bought[i] == t) {
				//books_bought.erase(books_bought.begin() + i);
				//break;
			//}
		//}
		

		if (c >= books_bought[t].first) {
			; //delete last one, but how to handle now last element?
		}
		else {
			books_bought[t].first -= c;
		}

		books_returned.push_back(t);
	}
*/
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
/*
	int getReturnedNum() {
		return books_returned.size();
	}
*/
	void getBooksBought() {
		
		for (int i = 0; i < books_bought.size(); i++) {
			std::cout << books_bought[i] << std::endl;
		}
		
		//for (auto i: books_bought) 
			//std::cout << x.first << std::endl;

		std::cout << std::endl;
	}
/*
	void getBooksReturned() {
		for (int i = 0; i < books_returned.size(); i++) {
			std::cout << books_returned[i] << std::endl;
		}

		std::cout << std::endl;
	}
*/
	//Other
	bool didBuyBook(string t) {
		//if (books_bought.find(t) == books_bought.end() - 1) {
			//return true;
		//}
		for (int i = 0; i < books_bought.size(); i++) {
			if (books_bought[i] == t) {
				return true;
			}
		}

		return false;
	}
};



void viewMembers(std::vector<Member>& mems);

void viewBooksBought(std::vector<Member>& mems);

//void viewBooksReturned(std::vector<Member>& mems);

void addMember(std::vector<Member>& mems);

void removeMember(std::vector<Member>& mems);

void modifyMember(std::vector<Member>& mems);

#endif