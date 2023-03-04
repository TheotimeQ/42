#ifndef CAT_H
#define CAT_H

#include <iostream>

#include "../incs/Animal.hpp"
#include "../incs/Brain.hpp"

class Cat : public Animal
{

	private:

		Brain* _Brain;

	public:

		Cat();
		Cat(const Cat& other);
		~Cat();

		virtual void makeSound() const;

		Cat& operator=(const Cat& other);

		Brain *brain() const;
};

#endif
