#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>

#include "../incs/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:
	
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		void makeSound() const;

		WrongCat& operator=(const WrongCat& other);
};

#endif
