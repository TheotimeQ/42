#include <string>
#include <iostream>

#include "../incs/Intern.hpp"
#include "../incs/Shrubberycreationform.hpp"
#include "../incs/Robotomyrequestform.hpp"
#include "../incs/Presidentialpardonform.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{

}

Form* Intern::makeForm(const std::string& form, const std::string& target)
{
	const std::string forms_name[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm",};

	int form_index;
	for (form_index = 0; form_index < 3; form_index++)
	{
		if (forms_name[form_index] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			switch (form_index)
			{
				case 0: return new PresidentialPardonForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new ShrubberyCreationForm(target);
			}
		}

	}
	std::cout << form << " not found" << std::endl;
	return NULL;
}


