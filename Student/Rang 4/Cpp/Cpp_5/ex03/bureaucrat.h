#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	void increment();
	void decrement();

	void signForm(const Form& form) const;
	void executeForm(const Form& form) const;

	const std::string& name() const;
	int grade() const;

	Bureaucrat& operator=(const Bureaucrat& other);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade too low";
		}
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);

#endif // BUREAUCRAT_H
