#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"

ClapTrap::ClapTrap() : _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0)
{
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _Name(name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0)
{
	std::cout << "ClapTrap " << _Name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _Name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if ( _Energy_Points <= 0)
		return;
	if ( _Hit_Points <= 0)
		return;

	_Energy_Points--;

	std::cout << "ClapTrap  : " << _Name << std::endl;
	std::cout << "Attack    : " << target << std::endl;
	std::cout << "Domage    : " << _Attack_Damage << std::endl;
	std::cout << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_Hit_Points -= amount;

	if (_Hit_Points < 0)
		_Hit_Points = 0;

	std::cout << "ClapTrap  : " << _Name << std::endl;
	std::cout << "Take      : " << amount << " domagge" << std::endl;
	std::cout << "Hp    	  : " << _Hit_Points << std::endl; 
	std::cout << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energy_Points <= 0)
		return;
	if (_Hit_Points <= 0)
		return;

	_Hit_Points += amount;
	_Energy_Points--;

	std::cout << "ClapTrap  : " << _Name << std::endl;
	std::cout << "Repaired  : " << amount << " domagge" << std::endl;
	std::cout << "Hp    	  : " << _Hit_Points << std::endl;
	std::cout << std::endl; 
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_Name = other._Name;
	_Hit_Points = other._Hit_Points;
	_Energy_Points = other._Energy_Points;
	_Attack_Damage = other._Attack_Damage;
	return *this;
}

const std::string& ClapTrap::name() const
{
	return _Name;
}

int ClapTrap::attackDamage() const
{
	return _Attack_Damage;
}
