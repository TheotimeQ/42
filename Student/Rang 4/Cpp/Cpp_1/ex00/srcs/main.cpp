#include <string>
#include <iostream>

#include "../incs/Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *Zb_On_Heap = newZombie("Zombie on the heap");
	if (!Zb_On_Heap)
		return (1);
	Zb_On_Heap->announce();
	delete Zb_On_Heap;
	randomChump("Zombie on the stack");
	return (0);
}
