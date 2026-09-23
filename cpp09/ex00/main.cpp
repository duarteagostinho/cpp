#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange btc;

	try {
		btc.createDB("data.csv");
		btc.parseFile(av[1]);
		btc.printBitcoin();
	}
	catch (...) {
	}
	return 0;
}
