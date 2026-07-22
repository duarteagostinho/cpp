#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <map>

class BitcoinExchange {
	
	private:
		std::map<std::string, float>	_db;
		std::map<std::string, float>	_inputFile;

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
		void	printBitcoin();
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);

#endif
