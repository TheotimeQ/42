#include <string>
#include <iostream>

#include "../incs/Bureaucrat.hpp"


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
