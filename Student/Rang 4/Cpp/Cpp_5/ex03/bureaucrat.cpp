#include "bureaucrat.h"
#include "form.h"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name),
	_grade(other._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::increment()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(const Form& form) const
{
	if (form.signGrade() < _grade)
		std::cout << _name << " couldn’t sign " << form.name() << " because of insufficient grade" << std::endl;
	else if (form.isSigned())
		std::cout << _name << " couldn’t sign " << form.name() << " because it is already signed" << std::endl;
	else
		std::cout << _name << " signed " << form.name() << std::endl;
}

void Bureaucrat::executeForm(const Form &form) const
{
	if (!form.isSigned())
		return;
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.name() << std::endl;
	}
	catch (...)
	{
		std::cout << _name << " couldn't execute " << form.name() << std::endl;
	}
}

const std::string& Bureaucrat::name() const
{
	return _name;
}

int Bureaucrat::grade() const
{
	return _grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::string* tmp = (std::string*)&_name;

	*tmp = other._name;
	_grade = other._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
	out << a.name() << ", bureaucrat grade " << a.grade();
	return out;
}
