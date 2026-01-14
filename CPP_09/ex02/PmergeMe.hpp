#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>


class PmergeMe{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);

    template <typename T> void sort(T&);
    void run(int, char**);
    void parse(int, char**);
    void printContainer();
    bool isValidNumber(const std::string&);
private:
    std::vector<int> vec;
    std::deque<int> deq;
};
#endif
