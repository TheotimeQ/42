#ifndef DOG_H
#define DOG_H

#include <iostream>

#include "../incs/Animal.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog(const Dog& other);
		~Dog();

		virtual void makeSound() const;

		Dog &operator=(const Dog& other);

};

#endif
