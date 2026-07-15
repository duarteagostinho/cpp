#include "Array.hpp"

int main() {
	std::cout << "--- Empty array ---" << std::endl;
	try {
		Array<int> empty;
		empty[0] = 42;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "--- Standard test ---" << std::endl;
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

	std::cout << "--- Out of bounds ---" << std::endl;
	try {
		std::cout << arr[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---  Copy constructor ---" << std::endl;
	Array<int> copy(arr);
	arr[0] = 42;
	std::cout << "original: " << arr[0] << std::endl;
	std::cout << "copy: " << copy[0] << std::endl;

	std::cout << "--- Assignment operator ---" << std::endl;
	Array<int> assigned(1);
	assigned = arr;
	arr[0] = 99;
	std::cout << "original: " << arr[0] << std::endl;
	std::cout << "assigned: " << assigned[0] << std::endl;

	std::cout << "--- Const array ---" << std::endl;
	Array<int> const cnst(arr);
	std::cout << cnst[3] << std::endl;

	std::cout << "--- String array ---" << std::endl;
	Array<std::string> strs(2);
	strs[0] = "ola";
	strs[1] = "mundo";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << strs[i] << std::endl;
}
