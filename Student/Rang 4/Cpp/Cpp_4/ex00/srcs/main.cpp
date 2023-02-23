#include <string>
#include <iostream>

#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongCat.hpp"

int main()
{
	//Cat
	Animal *Cat_1 = new Cat();
	std::cout << Cat_1->getType() << std::endl;
	Cat_1->makeSound();
	delete Cat_1;
	std::cout << std::endl;

	//Dog
	Animal *Dog_1 = new Dog();
	std::cout << Dog_1->getType() << std::endl;
	Dog_1->makeSound();
	delete Dog_1;
	std::cout << std::endl;

	//Animal
	Animal *Ani_1 = new Animal();
	std::cout << Ani_1->getType() << std::endl;
	Ani_1->makeSound();
	delete Ani_1;
	std::cout << std::endl;

	//Wrong Cat
	WrongAnimal *W_Cat = new WrongCat();
	std::cout << W_Cat->getType() << std::endl;
	W_Cat->makeSound();
	delete W_Cat;
	std::cout << std::endl;

	//Wrong Animal
	WrongAnimal *W_Ani = new WrongAnimal();
	std::cout << W_Ani->getType() << std::endl;
	W_Ani->makeSound();
	delete W_Ani;
	std::cout << std::endl;
}
