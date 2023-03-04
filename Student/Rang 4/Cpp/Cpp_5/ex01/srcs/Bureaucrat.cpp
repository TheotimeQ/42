#include <string>
#include <iostream>

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

//------------------------------------------Coplien--------------------------------
Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_Name(name),
	_Grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_Name(other._Name), 
	_Grade(other._Grade)
{
	if (_Grade < 1)
		throw GradeTooHighException();
	if (_Grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::string* tmp = (std::string*)&_Name;
	*tmp = other._Name;

	// _Name = other._Name;
	_Grade = other._Grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

//------------------------------------------Methodes--------------------------------
void Bureaucrat::signForm(Form& form) const
{
	if (form.Get_Sign_Garde() < _Grade)
		std::cout << _Name << " couldn’t sign " << form.name() << " because of insufficient grade" << std::endl;
	else if (form.Get_Sign_Status())
		std::cout << _Name << " couldn’t sign " << form.name() << " because it is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << _Name << " signed " << form.name() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void Bureaucrat::increment()
{
	if (_Grade <= 1)
		throw GradeTooHighException();
	_Grade--;
}

void Bureaucrat::decrement()
{
	if (_Grade >= 150)
		throw GradeTooLowException();
	_Grade++;
}

//------------------------------------------Getters--------------------------------
const std::string& Bureaucrat::name() const
{
	return _Name;
}

int Bureaucrat::grade() const
{
	return _Grade;
}

//------------------------------------------Other--------------------------------
std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
	out << a.name() << ", bureaucrat grade " << a.grade();
	return out;
}
