# include <iostream>
# include <string>

#include "../incs/Weapon.hpp"
#include "../incs/HumanA.hpp"
#include "../incs/HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		HumanB naked("naked");
		naked.attack();
	}
	return 0;
}