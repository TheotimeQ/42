# include <iostream>
# include <string>

#include "../incs/Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const std::string& type) : type(type)
{
	std::cout << this->type << ": weapon created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << this->type << ": weapon destroyed" << std::endl;
}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
