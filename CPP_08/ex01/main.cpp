#include "Span.hpp"

int main()
{
    // try 
	// {
    //     Span sp(100);
	// 	sp.fill();

    //     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    //     std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    // }
    // catch (const std::exception& e) 
	// {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // return 0;


    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    // std::vector<int> sorted = sp.v;
    // std::sort(sorted.begin(), sorted.end());
    // for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
    //     std::cout << *it << std::endl; 

    // }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}
