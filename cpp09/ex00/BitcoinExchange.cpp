#include "BitcoinExchange.hpp"
#include <cctype>
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
    if (this != &src)
		this->_db = src._db;
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
	std::map<std::string, double>::iterator it;

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
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int y = std::atoi(date.substr(0, 4).c_str());
	int m = atoi(date.substr(5,2).c_str());
	int d = atoi(date.substr(8, 2).c_str());
	if (m < 1 || m > 12)
		return false;
	int daysInM[] = {31, 28 + isLeap(y), 31,30,31,30,31,31,30,31,30,31};
	if (d < 1 || d > daysInM[m - 1])
		return false;
	return true;
}

static std::string strSplit(const std::string &s) {
	size_t start = 0;
	while (start < s.size() && (s[start] == ' ' || s[start] == '\t'
		|| s[start] == '\r' || s[start] == '\n'))
		start++;
	size_t end = s.size();
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'
		|| s[end - 1] == '\r' || s[end - 1] == '\n'))
		end--;
	return s.substr(start, end - start);
}

static void printBadInput(const std::string &s) {
	std::cout << "Error: bad input => " << s << std::endl;
}

static bool parseValue(const std::string &s, double &out) {
	if (s.empty())
		return false;
	char *end = NULL;
	double v = std::strtod(s.c_str(), &end);
	if (end == s.c_str())
		return false;
	if (*end != '\0')
		return false;
	out = v;
	return true;
}

void	BitcoinExchange::createDB(std::string file) {
	if (file.empty())
		throw std::runtime_error("Error: could not open file.");
	
	std::ifstream	stream(file.c_str());
	if (!stream)
		throw std::runtime_error("Error: could not open file.");
	std::string		line;
	std::string		date;
	double			rate;
	size_t			div;

	while (std::getline(stream, line)) {
		if (line.empty() || line == "date,exchange_rate")
			continue;
		div = line.find(',');
		if (div == std::string::npos)
			continue;
		date = strSplit(line.substr(0, div));
		if (!validDate(date))
			continue;
		rate = std::atof(strSplit(line.substr(div + 1)).c_str());
		_db[date] = rate;
	}
	if (_db.empty())
		throw std::runtime_error("Error: database is empty.");
}

bool	BitcoinExchange::findRate(const std::string &date, double &rate) {
	std::map<std::string, double>::iterator it = _db.lower_bound(date);
	if (it != _db.end() && it->first == date) {
		rate = it->second;
		return true;
	}
	if (it == _db.begin())
		return false;
	--it;
	rate = it->second;
	return true;
}

void	BitcoinExchange::processLine(const std::string &line) {
	size_t div = line.find('|');
	if (div == std::string::npos) {
		printBadInput(line);
		return;
	}
	std::string date = strSplit(line.substr(0, div));
	std::string valStr = strSplit(line.substr(div + 1));
	if (!validDate(date)) {
		if (date.empty())
			printBadInput(line);
		else
			printBadInput(date);
		return;
	}
	double value = 0;
	if (!parseValue(valStr, value)) {
		printBadInput(date);
		return;
	}
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	double rate = 0;
	if (!findRate(date, rate)) {
		printBadInput(date);
		return;
	}
	std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

void	BitcoinExchange::parseFile(std::string file) {
	if (file.empty())
		throw std::runtime_error("Error: could not open file.");
	std::ifstream	stream(file.c_str());
	if (!stream)
		throw std::runtime_error("Error: could not open file.");
	std::string		line;
	bool			firstLine = true;

	while (std::getline(stream, line)) {
		if (line.empty())
			continue;
		if (firstLine && strSplit(line) == "date | value") {
			firstLine = false;
			continue;
		}
		firstLine = false;
		processLine(line);
	}
}
