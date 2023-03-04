#include <string>
#include <iostream>

#include "../incs/Dog.hpp"

Dog::Dog() : Animal(), _Brain(new Brain)
{
	type = "Dog";
	std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _Brain(new Brain)
{
	*_Brain = *other._Brain;
	std::cout << "Dog copy created." << std::endl;
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "wooooofwooof" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	*_Brain = *other._Brain;
	return *this;
}

Brain *Dog::brain() const
{
	return _Brain;
}