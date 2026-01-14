#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2){
        throw std::runtime_error("Invalid arguments");
        return 1;
    }
    PmergeMe pm;
    pm.run(ac, av);
    return 0;
}
