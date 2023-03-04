#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{

	protected:

		std::string 	_Name;
		int 			_Hit_Points;
		int 			_Energy_Points;
		int 			_Attack_Damage;

	public:

		ClapTrap();
		ClapTrap(const std::string& name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap& operator=(const ClapTrap &other);

		const std::string& 		name() const;
		int 					attackDamage() const;

};

#endif
