#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>

int	doOp(char op, int a, int b) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (a == 0 || b == 0) {
				std::cerr << "Can't divide by 0\n";
				return 1;
			}
			else return b / a;
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
	std::stack<int>	stack;
	size_t i = 0;

	while (iss >> input){
		if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')) {	
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
			int n = std::atoi(input.c_str());
			stack.push(n);
		}
	}
	std::cout << stack.top() << std::endl;
}
