#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
    if (this == &other)
        return (*this);
    *this = other;
    return (*this);
}

bool ScalarConverter::isInf(const std::string &num){
    if (num == "inf" || num == "+inf" || num == "inff" || num == "+inff" || num == "-inf" || num == "-inff")
        return true;
    return false;
}


bool ScalarConverter::isValid(const std::string &num){
    if (num.empty())
        return false;

    size_t i = (num[0] == '+' || num[0] == '-') ? 1 : 0;
    if (i >= num.size())
        return false;

    bool dot = false;
    bool digit = false;
    size_t len = num.length();
    if (num[len - 1] == 'f')
        --len;
    for (; i < len; ++i)
    {
        if (num[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (std::isdigit(num[i]))
            digit = true;
        else
            return false;
    }
    return digit;
}

void ScalarConverter::printNan(){
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  nanf" << std::endl;
    std::cout << "double: nan" << std::endl; 
}


void ScalarConverter::printInf(const std::string& num){
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << (num[0] == '-' ? "-" : "+") << "inff" << std::endl;
    std::cout << "double: " << (num[0] == '-' ? "-" : "+") << "inf" << std::endl; 
}

void ScalarConverter::printError(void)
{
	std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    impossible" << std::endl;
	std::cout << "float:  impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convertToChar(const std::string& num){
    char c = static_cast<char>(std::atoi(num.c_str()));
    std::cout << "char:   ";
    if (c < 0)
        std::cout << "impossible" << std::endl;
    else if (c < 32 || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
}


void ScalarConverter::convertToInt(const std::string& num){
    std::cout << "int:    " << std::atoi(num.c_str()) << std::endl;
}


void ScalarConverter::convertToFloat(const std::string& num){
    float f = std::strtof(num.c_str(), NULL);
    std::cout << "float:  " << f;
    if (f == static_cast<int>(f))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}
    

void ScalarConverter::convertToDouble(const std::string& num){
    double d = std::strtod(num.c_str(), NULL);
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& num){
    if (num == "nan" || num == "nanf")
        printNan();
    else if (isInf(num))
        printInf(num);
    if (isValid(num))
    {
        convertToChar(num);
        convertToInt(num);
        convertToFloat(num);
        convertToDouble(num);
    }
    else
        printError();
}