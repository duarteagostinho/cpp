#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

BitcoinExchange::BitcoinExchange() {
    // std::cout << "Default Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
		   *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
		this->_db = src._db;
		this->_inputFile = src._inputFile;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i) {
    (void)i; // Evita erro de 'unused parameter' até adicionares lógica
    o << "Type: BitcoinExchange";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::printDatabase() {
	std::map<std::string, float>::iterator it;

	it = _db.begin();
	while (it != _db.end()) {
		std::cout << it->first << " = " << it->second << std::endl;
		it++;
	}
}

bool isLeap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	BitcoinExchange::validDate(std::string date) {
	if (date.empty() || date.size() != 10)
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > 2026)

	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int	dayscount[] = {31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeap(year) == true) {
		if (day >= 1 && day <= dayscount[month - 1])
			return true;
	} 
	if (year < 2009 || (month > 12 || month < 1) || (day > 31 || day < 1))
		return false;
	return true;
}

// bool	validValue(float val) {
//
// }
//
void	BitcoinExchange::createDB(std::string file) {
	if (file.empty())
		return ;
	
	std::ifstream	stream(file);
	if (!stream)
		throw std::runtime_error("Error: could not open file\n");
	std::string		line;
	std::string		date;
	float			rate;
	size_t			div;

	while (std::getline(stream, line)) {
		if (line.empty() || line == "date,exchange_rate")
			continue;
		div = line.find(',');
		if (div == std::string::npos)
			continue;
		date = line.substr(0, div);
		rate = std::atof(line.substr(div + 1, line.npos).c_str());
		_db[date] = rate;
	}
}

void	BitcoinExchange::parseFile(std::string file) {
	if (file.empty())
		return ;
	std::ifstream	stream(file);
	if (!stream) {
		std::cerr << "Couldn't open file\n";
		return;
	}
	std::string line;
	std::string		date;
	float			value;
	size_t		div;

	while (std::getline(stream, line)) {
		if (line.empty())
			continue;
		div = line.find(',');
		date = line.substr(0, div);
		value = std::atof(line.substr(div + 1, line.npos).c_str());
		_inputFile[date] = value;
	}
}

void	BitcoinExchange::printBitcoin() {
	std::map<std::string, float>::iterator it;

	for (it = _inputFile.begin(); it != _inputFile.end(); it++) {
		std::string date = it->first;
		if (validDate(date) == true)
			std::cout << it->first << " => " << it->second << std::endl;
		else
			std::cerr << "Invalid date\n";
	}
}
