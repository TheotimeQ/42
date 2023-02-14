#include <string>

#include "../incs/Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *Zb = new Zombie(name);
	return (Zb);
}
