#include <string>
#include <iostream>

#include "../incs/Presidentialpardonform.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	Form("PresidentialPardonForm", 25, 5),
	_target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	Form(other),
	_target(other._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	if (!Get_Sign_Status())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	if (bureaucrat.grade() > Get_Exec_Garde())
		throw GradeTooLowException();

	//-----------------Behaviour----------------------
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}
