#ifndef CAT_H
#define CAT_H

#include <iostream>

#include "../incs/Animal.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat(const Cat& other);
		~Cat();

		virtual void makeSound() const;

		Cat& operator=(const Cat& other);

};

#endif
