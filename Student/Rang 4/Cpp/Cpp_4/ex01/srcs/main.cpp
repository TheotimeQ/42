#include <string>
#include <iostream>

#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongCat.hpp"

int main()
{
	Animal *animals[6];

	//Cat
	for (int i = 0; i < 3; i++)
		animals[i] = new Cat;

	//Dog
	for (int i = 3; i < 6; i++)
		animals[i] = new Dog;

	//Sound
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		animals[i]->makeSound();
	std::cout << std::endl;

	//Delete
	for (int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << std::endl;

	Cat Cat_1;
	Cat_1.brain()->idea(0) = "I love my mum";

	Cat Cat_2(Cat_1);
	Cat_2.brain()->idea(1) = "I would like to eat pasta";

	std::cout << std::endl;
	std::cout << Cat_1.brain()->idea(0) << std::endl;
	std::cout << Cat_2.brain()->idea(0) << std::endl;
	std::cout << Cat_2.brain()->idea(1) << std::endl;
	std::cout << std::endl;
}
