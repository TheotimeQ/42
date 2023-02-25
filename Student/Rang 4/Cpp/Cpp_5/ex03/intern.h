#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include "form.h"
#include "shrubberycreationform.h"
#include "robotomyrequestform.h"
#include "presidentialpardonform.h"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Form* makeForm(const std::string& form, const std::string& target);

	Intern& operator=(const Intern& other);
};

#endif // INTERN_H
