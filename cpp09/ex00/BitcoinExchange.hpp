#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <map>

class BitcoinExchange {
	
	private:
		std::map<std::string, double>	_db;

		bool	findRate(const std::string &date, double &rate);
		void	processLine(const std::string &line);

	public:
        // Constructors & Destructor
        BitcoinExchange();                                  // Default
        BitcoinExchange(const BitcoinExchange &src);            // Copy
        ~BitcoinExchange();                                 // Destructor

        // Operators
        BitcoinExchange &operator=(const BitcoinExchange &src); // Copy Assignment
		
		void	createDB(std::string file);
		void	printDatabase();
		bool	validDate(std::string date);
		void	parseFile(std::string file);
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);

#endif
