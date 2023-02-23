#include <string>
#include <iostream>

#include "../incs/Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy created." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "wouf" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return *this;
}
