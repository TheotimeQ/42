#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"
#include "../incs/Scavtrap.hpp"

int main()
{
	ClapTrap Clap_1("Clap");
	ScavTrap Scav_1("Scav");
	std::cout << std::endl;

	Scav_1.attack(Clap_1.name());
	Clap_1.takeDamage(Scav_1.attackDamage());
	std::cout << std::endl;

	Clap_1.attack(Scav_1.name());
	Scav_1.takeDamage(Clap_1.attackDamage());
	std::cout << std::endl;

	Clap_1.takeDamage(12);
	Scav_1.takeDamage(5);
	std::cout << std::endl;

	Clap_1.beRepaired(5);
	Scav_1.beRepaired(5);
	std::cout << std::endl;

	Scav_1.guardGate();
	std::cout << std::endl;

	return 0;
}
