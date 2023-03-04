#include <string>
#include <iostream>

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

//------------------------------------------Coplien--------------------------------
Form::Form(const std::string& name, int Get_Sign_Garde, int Get_Exec_Garde) :
	_Name(name),
	_Signed(false),
	_Sign_Grade(Get_Sign_Garde),
	_Exec_Grade(Get_Exec_Garde)
{
	if (_Sign_Grade < 1 || _Exec_Grade < 1)
		throw GradeTooHighException();
	if (_Sign_Grade > 150 || _Exec_Grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) :
	_Name(other._Name),
	_Signed(other._Signed),
	_Sign_Grade(other._Sign_Grade),
	_Exec_Grade(other._Exec_Grade)
{
	if (_Sign_Grade < 1 || _Exec_Grade < 1)
		throw GradeTooHighException();
	if (_Sign_Grade > 150 || _Exec_Grade > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	std::string* tmp = (std::string*)&_Name;
	*tmp = other._Name;

	int* tmp_sign = (int*)&_Sign_Grade;
	*tmp_sign = other._Sign_Grade;

	int* tmp_exec = (int*)&_Exec_Grade;
	*tmp_exec = other._Exec_Grade;
	
	// _Name = other._Name;
	_Signed = other._Signed;
	// _Sign_Grade = other._Sign_Grade;
	// _Exec_Grade = other._Exec_Grade;
	return *this;
}

Form::~Form()
{

}

//------------------------------------------Methodes--------------------------------
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_Signed)
	{
		std::cout << "Form already signed" << std::endl;
		return;
	}
	if (bureaucrat.grade() >= _Sign_Grade)
		throw GradeTooLowException();
	_Signed = true;
}

//------------------------------------------Getters--------------------------------
const std::string& Form::name() const
{
	return _Name;
}

bool Form::Get_Sign_Status() const
{
	return _Signed;
}

int Form::Get_Sign_Garde() const
{
	return _Sign_Grade;
}

int Form::Get_Exec_Garde() const
{
	return _Exec_Grade;
}

//------------------------------------------Others--------------------------------
std::ostream& operator<<(std::ostream& out, const Form& a)
{
	std::cout << a.name() << ", signed: " << a.Get_Sign_Status() << ", sign: " << a.Get_Sign_Garde() << ", exec: " << a.Get_Exec_Garde() << std::endl;
	return out;
}
