#ifndef INTERN_H
# define INTERN_H

#include <string>
#include <iostream>

#include "../incs/Form.hpp"

class Intern
{
	public:

		//Coplien
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		//Methodes
		Form* makeForm(const std::string& form, const std::string& target);

};

#endif
