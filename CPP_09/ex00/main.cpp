#include "BitcoinExchange.hpp"


int main(int argc, char **argv){
    try{
        if (argc != 2)
            throw std::invalid_argument("missing input file");
        BitcoinExchange btc("data.csv");
        std::string fileName(argv[1]);
        btc.exchange(fileName);        
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}