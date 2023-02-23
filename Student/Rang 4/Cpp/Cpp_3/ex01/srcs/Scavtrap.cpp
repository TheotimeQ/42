#include <string>
#include <iostream>

#include "../incs/Scavtrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_Hit_Points = 100;
	_Energy_Points = 50;
	_Attack_Damage = 20;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) 
{
	_Hit_Points = 100;
	_Energy_Points = 50;
	_Attack_Damage = 20;
	std::cout << "ScavTrap " << _Name << " created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _Name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if ( _Energy_Points <= 0)
		return;
	if ( _Hit_Points <= 0)
		return;

	_Energy_Points--;

	std::cout << "ScavTrap  : " << _Name << std::endl;
	std::cout << "Attack    : " << target << std::endl;
	std::cout << "Domage    : " << _Attack_Damage << std::endl;
	std::cout << std::endl; 
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _Name << " in guard mode." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}
