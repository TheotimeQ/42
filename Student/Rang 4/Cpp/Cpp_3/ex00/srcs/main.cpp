#include <string>
#include <iostream>

#include "../incs/Claptrap.hpp"

int main()
{
	ClapTrap Clap_1;
	ClapTrap Clap_2("Clap_2");
	std::cout << std::endl;

	Clap_1.attack(Clap_2.name());
	Clap_2.takeDamage(Clap_1.attackDamage());
	std::cout << std::endl;

	Clap_2.attack(Clap_1.name());
	Clap_1.takeDamage(Clap_2.attackDamage());
	std::cout << std::endl;

	Clap_1.takeDamage(12);
	Clap_2.takeDamage(5);
	std::cout << std::endl;
    
	Clap_1.beRepaired(5);
	Clap_2.beRepaired(5);
	std::cout << std::endl;

	return 0;
}
