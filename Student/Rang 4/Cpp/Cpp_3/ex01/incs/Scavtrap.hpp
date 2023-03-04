#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(const std::string& name);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap &other);
		
		void attack(const std::string& target);
		void guardGate();


};

#endif
