#include <string>
#include <iostream>
#include <fstream>

#include "../incs/Shrubberycreationform.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	Form("ShrubberyCreationForm", 145, 137),
	_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	Form(other),
	_target(other._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!Get_Sign_Status())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	if (bureaucrat.grade() > Get_Exec_Garde())
		throw GradeTooLowException();

	//-----------------Behaviour----------------------

	std::ofstream out((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!out.is_open())
	{
		std::cout << "Couldn't open file" << std::endl;
		return ;
	}
	out << "  &&&&       &&&&     " << std::endl;
	out << " &&&&&&     &&&&&&    " << std::endl;
	out << "  &&&&       &&&&     " << std::endl;
	out << "   ||-        ||-@    " << std::endl;
	out << " --||        -||      " << std::endl;
	out << "   ||         ||      " << std::endl;
	out << "----------------------" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}
