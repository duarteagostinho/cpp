#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <limits>

int	doOp(char op, int a, int b) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0) {
				std::cerr << "Can't divide by 0\n";
				return 1;
			}
			else return a / b;
		}
	return 0;
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Wrong argument number\n";
		return 1;
	}
	std::istringstream iss(av[1]);
	std::string input;
	std::stack<float>	stack;
	size_t i = 0;

	while (iss >> input) {
		if (input.length() != 1) { 
				std::cerr << "Error\n";
				return 1;
		}
		else {
			if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/') {	
				if (stack.size() < 2) {
					std::cerr << "Error\n";
					return 1;
				}
				int b = stack.top();
				stack.pop();
				int a = stack.top();
				stack.pop();
				stack.push(doOp(input[i], a, b));
			}
			else {
				int n = std::strtof(input.c_str(), NULL);
				if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min()) {
					std::cerr << "Error\n";
					return 1;
				}
				stack.push(n);
			}
		}
	}
	if (stack.size() != 1){
		std::cerr << "Error\n";
		return 1;
	}
	std::cout << stack.top() << std::endl;
}
