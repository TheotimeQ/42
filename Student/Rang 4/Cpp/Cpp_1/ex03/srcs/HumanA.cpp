# include <iostream>
# include <string>

#include "../incs/HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << this->name << ": Created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
}
