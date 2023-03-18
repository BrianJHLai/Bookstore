#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
using std::string;

#ifndef EMPLOY_H_INCLUDED
#define EMPLOY_H_INCLUDED


class Employee {
  private:
  	//Attribute
	string name;
	string address;
	string position;
	float salary;

  public:
  	//Constructors
	Employee(string n, string a, string p, float s) {
		name = n;
		address = a;
		position = p;
		salary = s;
	}

	//Setters
	void changeName(string n) {
		name = n;
	}

	void changeAddress(string a) {
		address = a;
	}

	void changePosition(string p) {
		position = p;
	}

	void changeSalary(float s) {
		;salary = s;
	}

	//Getters
	string getName() {
		return name;
	}

	string getAddress() {
		return address;
	}

	string getPosition() {
		return position;
	}

	float getSalary() {
		return salary;
	}
};

void nonEmptyInput(string& input);

float getFloat();

void viewEmployees(std::vector<Employee>& emps);

void addEmployee(std::vector<Employee>& emps);

void removeEmployee(std::vector<Employee>& emps);

void modifyEmployee(std::vector<Employee>& emps);

#endif