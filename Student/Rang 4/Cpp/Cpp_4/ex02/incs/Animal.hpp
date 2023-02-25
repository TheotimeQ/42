#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	protected:

		std::string type;
	
	public:

		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		virtual void makeSound() const = 0;

		Animal& operator=(const Animal& other);

		const std::string& getType() const;

};

#endif
