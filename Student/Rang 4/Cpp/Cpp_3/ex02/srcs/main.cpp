#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"
#include "../incs/Scavtrap.hpp"
#include "../incs/Fragtrap.hpp"

int main()
{
	FragTrap Frag_1("Frag");
	ScavTrap Scav_1("Scav");
	std::cout << std::endl;

	Scav_1.attack(Frag_1.name());
	Frag_1.takeDamage(Scav_1.attackDamage());
	std::cout << std::endl;

	Frag_1.attack(Scav_1.name());
	Scav_1.takeDamage(Frag_1.attackDamage());
	std::cout << std::endl;

	Frag_1.takeDamage(12);
	Scav_1.takeDamage(5);
	std::cout << std::endl;

	Frag_1.beRepaired(5);
	Scav_1.beRepaired(5);
	std::cout << std::endl;

	Scav_1.guardGate();
	Frag_1.highFivesGuy();
	std::cout << std::endl;

	return 0;
}


