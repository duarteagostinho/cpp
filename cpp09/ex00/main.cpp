#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2)
		std::cerr << "Invalid number of arguments\n";
	BitcoinExchange btc;

	btc.createDB("data.csv");
	btc.parseFile(av[1]);
	btc.printBitcoin();
}
