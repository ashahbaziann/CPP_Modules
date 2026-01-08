#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): data(other.data){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->data = other.data;
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &fname)
{
	(void)fname;
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open data.csv");
    }
	std::string line;
	std::getline(file,line);
	while (std::getline(file,line)){
		size_t pos = line.find(',');
		if(pos ==std::string::npos)
			throw std::runtime_error("Invalid format");
		std::string key = trim(line.substr(0, pos));
		std::string val = trim(line.substr(pos + 1));

		double value = std::atof(val.c_str());
		data.insert(std::make_pair(key, value));
	}
}

BitcoinExchange::~BitcoinExchange(){}

bool	BitcoinExchange::isValidDateFormat(const std::string& date)
{
	if (date.length() != 10)
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i == 4 || i == 7))
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	int year, month, day;
	if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
		return false;
	if (month < 1 || month > 12 || day < 1 || year == 0)
		return false;
	switch (month)
	{
		case February:
			return (day <= (year % 4 == 0 ? 29 : 28));
		case April:
		case June:
		case September:
		case November:
			return (day <= 30);
		default:
			return (day <= 31);
	}
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end   = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}


bool BitcoinExchange::isValidValue(const std::string &value)
{
	double num;
	std::stringstream ss(value);
	ss >> num;
	if (ss.fail() || !ss.eof())
	{
		std::cout << "Error: bad input1" << std::endl;
		return false;
	}
	else if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}


void BitcoinExchange::exchange(std::string &str){
    std::ifstream file(str.c_str());
    if(!file.is_open() || file.eof())
        throw std::runtime_error("Couldn't open input file.");
    std::string line;
	std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid input file.");
    while(std::getline(file, line)){
        if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, pos));
		std::string value = trim(line.substr(pos + 1));
        if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		else if (!isValidValue(value))
			continue;
        else{
            double price = std::atof(value.c_str());
            std::map<std::string, double>::iterator it = this->data.lower_bound(date);
			if(it == this->data.end())
				it--; 
			else if(it->first != date)
			{
				if (it == data.begin())
				{
					std::cerr << "Error: no earlier date available => " << date << std::endl;
					continue;
				}
				--it;
			}
			std::cout << date << " => " << price << " = " << price * it->second << std::endl;	
        }
    }
    
}