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

		void attack(const std::string& target);
		void guardGate();

		ScavTrap& operator=(const ScavTrap &other);

};

#endif
