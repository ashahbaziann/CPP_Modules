#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce( void );  
    void setName(std::string name);
    std::string getName(void) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif