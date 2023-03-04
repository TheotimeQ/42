#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuy();

		FragTrap& operator=(const FragTrap &other);

};

#endif 
