#include <cmath>
#include "book.h"
#include "employee.h"
#include "supplier.h"
#include "member.h"
//#include "sales.h"

//Get a non-empty string from user input
//Worked previously, but currently broken. Unsure why
/*
string nonEmptyInput(string input) {
	std::getline(std::cin, input);
	std::cout << std::endl;

	if (input.empty()) {
		while (input.empty()) {
			std::cout << "Please give a non-empty input: "; //
			std::getline(std::cin, input);
			std::cout << std::endl;
		}
	}

	return input;
}
*/

//Get an integer from user input
int getInt() {
	string input;
	std::getline(std::cin, input);
	std::cout << std::endl;

	while (true) {
		bool not_int = false;

		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				not_int = true;
				break;
			}
		}
		if (input.empty() || not_int) {
			std::cout << "Please input an integer greater than 0: ";
			std::getline(std::cin, input);
			std::cout << std::endl;
			continue;
		}
		else if (stoi(input) == 0) {
			std::cout << "Please input an integer greater than 0: ";
			std::getline(std::cin, input);
			std::cout << std::endl;
			continue;
		}
		else if (!not_int) {
			return stoi(input);
		}
	}
}

//Get a float rounded to 2 decimals from user input
float getFloat() {
	string input;
	std::getline(std::cin, input);
	std::cout << std::endl;

	while (true) {
		bool not_float = false;
		int decimals = 0;

		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i]) && input[i] != '.') {
				not_float = true;
				break;
			}
			else if (!isdigit(input[i]) && input[i] == '.' && decimals == 1) {
				not_float = true;
				break;
			}
			else if (!isdigit(input[i]) && input[i] == '.') {
				decimals++;
			}
		}
		if (input.empty() || not_float) {
			std::cout << "Please input a number greater than 0.00: ";
			std::getline(std::cin, input);
			std::cout << std::endl;
			continue;
		}
		else if (stod(input) == 0) {
			std::cout << "Please input a number greater than 0.00: ";
			std::getline(std::cin, input);
			std::cout << std::endl;
			continue;
		}
		else if (!not_float) {
			return round(stod(input) * 100.0) / 100.0;
		}
	}
}