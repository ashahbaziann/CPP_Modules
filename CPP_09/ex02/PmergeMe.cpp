#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this -> vec = other.vec;
	this -> deq = other.deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
    {
        this -> vec = other.vec;
        this -> deq = other.deq;
    }
	return *this;
}

PmergeMe::~PmergeMe(){}

bool PmergeMe::isValidNumber(const std::string& s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]) || s.find_first_not_of("+0123456789") != std::string::npos || s.size() > 10)
            return false;
    }
    return true;
}

void PmergeMe::printContainer()
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<" "<<vec[i];
	std::cout<<std::endl;
}

void PmergeMe::parse(int ac, char **argv){
    for(int i = 1; i < ac; i++){
        std::string av(argv[i]);
        if(!isValidNumber(av))
            throw std::runtime_error("Invalid numeric argument!");
        std::stringstream ss(av);
        long val;
        ss >> val;
        if (ss.fail() || !ss.eof())
            throw std::runtime_error("Invalid numeric argument!");

        if (val > 2147483647L)
			throw std::runtime_error("Invalid numeric argument!");
        vec.push_back(static_cast<int> (val));
        deq.push_back(static_cast<int> (val));
    }
}

template <typename T>
void PmergeMe::sort(T& c){
    if (c.size() <= 1)
		return;
	T main, pending;
    for (size_t i = 0; i + 1 < c.size(); i += 2)
	{
		if (c[i] < c[i + 1])
		{
			main.push_back(c[i + 1]);
			pending.push_back(c[i]);
		}
		else
		{
			main.push_back(c[i]);
			pending.push_back(c[i + 1]);
		}
	}

    bool hasOdd = (c.size() % 2 == 1);
    int odd = hasOdd ? c.back() : 0;
    sort(main);

    for (size_t i = 0; i < pending.size(); i++){
        typename T::iterator pos = std::lower_bound(main.begin(), main.end(),pending[i]);
        main.insert(pos, pending[i]);
    }
    if (hasOdd)
	{
		typename T::iterator pos = std::lower_bound(main.begin(), main.end(), odd);
		main.insert(pos, odd);
	}
    c = main;
}

void PmergeMe::run(int ac, char **av){
    parse(ac, av);

    std::cout << "Before: ";
    printContainer();

    clock_t start = clock();
    sort(vec);
    clock_t end = clock();
    double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC ;

    start = clock();
    sort(deq);
    end = clock();
    double timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC ;

    std::cout << "After:  ";
    printContainer();

    std::cout << "Time to process a range of "
              << vec.size()
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of "
              << deq.size()
              << " elements with std::deque  : "
              << timeDeq << " us" << std::endl;
}