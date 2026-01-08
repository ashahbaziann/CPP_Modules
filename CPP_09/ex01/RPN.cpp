#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other): s(other.s){};

RPN &RPN::operator=(const RPN& other){
    if (this != &other)
        this->s = other.s;
    return *this;
};
static bool isOperator(const std::string &tkn){
    if (tkn == "+" || tkn == "-" || tkn == "*" || tkn == "/")
        return true;
    return false;
}
double RPN::evalRPN(const std::string &str){
    std::istringstream iss(str);
    std::string token;

    while (iss >> token){
        if (isOperator(token)){
            if (s.size() < 2)
                throw std::runtime_error("Invalid expression");
            double y = s.top();
            s.pop();
            double x = s.top();
            s.pop();
            if (token == "+") s.push(x + y);
            else if (token == "-") s.push(x - y);
            else if (token == "*") s.push(x * y);
            else if (token == "/") s.push(x / y);
        }
        else
            s.push(std::atof(token.c_str()));
    }
    if (s.size() != 1)
        throw std::runtime_error("Invalid expression");
    return s.top();
}