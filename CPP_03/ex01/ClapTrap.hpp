#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
private:
    std::string name;
    int hitPoints;//health of claptrap
    int energyPoints;
    int attackDamage;
public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string const getName() const;
    int get_hitPoints() const;
    int get_energyPoints() const;
    int get_attackDamage() const;
    void set_name(const std::string name);
    void set_hitPoints(int hitPoints);
    void set_energyPoints(int energy_points);
    void set_attackDamage(int attack_damage);
};

#endif