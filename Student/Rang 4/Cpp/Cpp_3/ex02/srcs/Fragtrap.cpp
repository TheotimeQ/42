#include <string>
#include <iostream>

#include "../incs/Fragtrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_Hit_Points = 100;
	_Energy_Points = 100;
	_Attack_Damage = 30;
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_Hit_Points = 100;
	_Energy_Points = 100;
	_Attack_Damage = 30;
	std::cout << "FragTrap " << _Name << " created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _Name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if ( _Energy_Points <= 0)
		return;
	if ( _Hit_Points <= 0)
		return;

	_Energy_Points--;

	std::cout << "Fragtrap  : " << _Name << std::endl;
	std::cout << "Attack    : " << target << std::endl;
	std::cout << "Domage    : " << _Attack_Damage << std::endl;
	std::cout << std::endl; 
}

void FragTrap::highFivesGuy()
{
	std::cout << "FragTrap " << _Name << " high five bro" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}
