#include "presidentialpardonform.h"

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
	if (!isSigned())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	if (bureaucrat.grade() > execGrade())
		throw GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}
