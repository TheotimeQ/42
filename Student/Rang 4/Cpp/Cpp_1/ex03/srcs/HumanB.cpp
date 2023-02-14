# include <iostream>
# include <string>

#include "../incs/HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
	std::cout << this->name << ": Created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void HumanB::attack() const
{
	if (!this->weapon)
	{
		std::cout << this->name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
