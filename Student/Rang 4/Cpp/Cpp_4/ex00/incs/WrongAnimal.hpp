#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{

	protected:
	
		std::string type;

	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		void makeSound() const;

		WrongAnimal& operator=(const WrongAnimal& other);

		const std::string& getType() const;
};

#endif
