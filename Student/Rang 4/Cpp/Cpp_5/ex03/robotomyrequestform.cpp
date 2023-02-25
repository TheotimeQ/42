#include "robotomyrequestform.h"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	Form("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	Form(other),
	_target(other._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	if (!isSigned())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	if (bureaucrat.grade() > execGrade())
		throw GradeTooLowException();

	if (rand() % 2)
		std::cout << _target << " Robotomy successful" << std::endl;
	else
		std::cout << _target << " Robotomy failed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}
