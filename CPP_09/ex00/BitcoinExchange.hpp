#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


enum Months {
		January = 1,
		February,
		March,
		April,
		May,
		June,
		Jule,
		August,
		September,
		October,
		November,
		December
	};

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &);
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange &operator=(const BitcoinExchange&);
    ~BitcoinExchange();
	
    void exchange(std::string&);
private:
    std::string trim(const std::string&);
    bool isValidValue(const std::string&);
    bool isValidDateFormat(const std::string&);
    bool isValidDate(const std::string&);
private:
    std::map<std::string, double> data;
};

#endif