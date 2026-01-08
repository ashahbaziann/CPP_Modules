#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr<<"Invalid arguments!" << std::endl;
		return 1;
	}
    std::string line(argv[1]);
    RPN polish;
	try {
        double result = polish.evalRPN(line);
        std::cout << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}