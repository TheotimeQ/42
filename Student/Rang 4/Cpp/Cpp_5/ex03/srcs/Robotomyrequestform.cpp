#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../incs/Robotomyrequestform.hpp"

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
	if (!Get_Sign_Status())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	if (bureaucrat.grade() > Get_Exec_Garde())
		throw GradeTooLowException();

	//-----------------Behaviour----------------------
	std::cout << "Zzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	sleep(1);
	std::cout << "Brrrrrrrrrrrrrzzzzzzzzzzzzzz" << std::endl;
	sleep(1);
	std::cout << "GlouGlouGlou" << std::endl;
	sleep(1);
	if (rand() > 0.5)
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
