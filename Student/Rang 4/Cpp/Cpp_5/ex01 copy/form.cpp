#include "form.h"
#include "bureaucrat.h"

Form::Form(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{

}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signed)
	{
		std::cout << "Form already signed" << std::endl;
		return;
	}
	if (bureaucrat.grade() >= _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const std::string& Form::name() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::signGrade() const
{
	return _signGrade;
}

int Form::execGrade() const
{
	return _execGrade;
}

Form& Form::operator=(const Form& other)
{
	std::string* tmp_name = (std::string*)&_name;
	int* tmp_signGrade = (int*)&_signGrade;
	int* tmp_execGrade = (int*)&_execGrade;

	*tmp_name = other._name;
	_signed = other._signed;
	*tmp_signGrade = other._signGrade;
	*tmp_execGrade = other._execGrade;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& a)
{
	std::cout << a.name() << ", signed: " << a.isSigned()
			  << ", sign: " << a.signGrade() << ", exec: " << a.execGrade() << std::endl;
	return out;
}
