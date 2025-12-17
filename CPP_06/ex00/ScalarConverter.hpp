#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
public:
    static void convert(const std::string&);
private:
    static bool isInf(const std::string&);
    static bool isValid(const std::string&);

    static void convertToInt(const std::string&);
    static void convertToChar(const std::string&);
    static void convertToFloat(const std::string&);
    static void convertToDouble(const std::string&);

    static void printInf(const std::string&);
    static void printNan();
    static void printError();
};

#endif