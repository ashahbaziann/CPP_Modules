#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN{
public:
    RPN();
    ~RPN();
    RPN(const RPN&);
    RPN &operator=(const RPN&);

    double evalRPN(const std::string &);
private:
    std::stack<double> s;
};

#endif