#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>

class Bureaucrat
{

	private:

		const std::string 	_Name;
		int 				_Grade;

	public:

		//Coplien
		Bureaucrat(const std::string& name, int grade); 
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		//Methodes
		void 				increment();
		void 				decrement();
		int 				grade() const;
		const std::string& 	name() const;

		//Exeception
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);

#endif
