#include <string>
#include <iostream>

#include "../incs/Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(const std::string &name) : name(name)
{
	std::cout << this->name << ": Created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Set_Name(const std::string &name)
{
	this->name = name;
}
