#include "intern.h"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{

}

Form* Intern::makeForm(const std::string& form, const std::string& target)
{
	const std::string forms[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm",
	};
	int idx;
	for (idx = 0; idx < 3; idx++)
		if (forms[idx] == form)
			break ;
	if (idx >= 3)
	{
		std::cout << form << " not found" << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << form << std::endl;
	switch (idx)
	{
	case 0: return new PresidentialPardonForm(target); break;
	case 1: return new RobotomyRequestForm(target); break;
	case 2: return new ShrubberyCreationForm(target); break;
	}
	return NULL;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
