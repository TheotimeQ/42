#include <string>

#include "../incs/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie Zb = Zombie(name);
	Zb.announce();
}