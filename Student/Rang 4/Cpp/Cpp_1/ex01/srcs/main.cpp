#include <string>

#include "../incs/Zombie.hpp"

#define Horde_Size 5

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* Zbs = zombieHorde(Horde_Size, "For the Hordeeeee");
	for (int i = 0; i < Horde_Size; i++)
		Zbs[i].announce();
	delete[] Zbs;
	return (0);
}
