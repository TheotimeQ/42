#ifndef DOG_H
#define DOG_H

#include <iostream>

#include "../incs/Animal.hpp"
#include "../incs/Brain.hpp"

class Dog : public Animal
{

	private:

		Brain* _Brain;

	public:

		Dog();
		Dog(const Dog& other);
		~Dog();

		virtual void makeSound() const;

		Dog &operator=(const Dog& other);

		Brain *brain() const;
};

#endif
