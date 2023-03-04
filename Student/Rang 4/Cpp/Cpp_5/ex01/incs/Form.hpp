#ifndef FORM_H
#define FORM_H

#include <string>

class Bureaucrat;

class Form
{

	private:

		const std::string 		_Name;
		bool 					_Signed;
		const int 				_Sign_Grade;
		const int 				_Exec_Grade;

	public:

		//Coplien
		Form(const std::string& name, int Get_Sign_Garde, int Get_Exec_Garde);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//Methodes
		void 				beSigned(const Bureaucrat& bureaucrat);

		//Getters
		const std::string& 	name() const;
		bool 				Get_Sign_Status() const;
		int 				Get_Sign_Garde() const;
		int 				Get_Exec_Garde() const;

		//Exception
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

std::ostream& operator<<(std::ostream& out, const Form& a);

#endif
