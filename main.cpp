#include<iostream>
#include<vector>
#include<string>
#include <regex>

#include "thing.h"

std::string priorities[4] = { "+", "-", "/", "*" };
bool error = false;

std::regex number("-?\\d+");
std::regex function("[a-zA-Z]\\w*\\(([a-zA-Z]\\w*)?(\\,[a-zA-Z]\\w*)*\\)");

Thing* parse(const std::vector<std::string>* elements, int l, int r) {
	if (l >= r) {
		error = true;
		return NULL;
	}

	for ( int i = 0; i < 4; i++ )
		for ( int mid = l; mid < r; mid++ )
			if ((*elements)[mid] == priorities[i])
				return new Thing(
						priorities[i][0],
						parse(elements, l, mid),
						parse(elements, mid + 1, r)
						);

	if (r - l != 1) {
		error = true;
		return NULL;
	}


	std::string str = (*elements)[l];
	if (regex_match(str, number)) {
		return new Thing(str);
	}

	if (regex_match(str, function)) {
		std::vector<std::string> args_vec;

		bool flg = false;
		std::string temp = "", name = "";
		for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
			if (*it == '(') {
				flg = true;
				name = temp;
				temp = "";
				continue;
			}

			if (flg) {
				if (*it == ',' || *it == ')') {
					args_vec.push_back(temp);
					temp = "";
				} else
					temp.push_back(*it);
			} else {
				temp.push_back(*it);
			}
		}

		return new Thing(new Func(name, &args_vec));
	}

	error = true;
	return NULL;
}


int main() {
	std::string input;
	std::getline(std::cin, input);
	input.push_back(' ');

	std::vector<std::string> elements;

	std::string temp;
	for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
		if (not isspace(*it)) {
			temp.push_back(*it);
		} else {
			if (temp != "")
				elements.push_back(temp);
			temp = "";
		}
	}

	Thing* t = parse(&elements, 0, elements.size());

	if (error) {
		std::cout << "ERROR" << std::endl;
		return -1;
	}

	int result = t->eval();

	if (error) {
		std::cout << "ERROR" << std::endl;
		return -1;
	}

	std::cout << result << std::endl;
}
