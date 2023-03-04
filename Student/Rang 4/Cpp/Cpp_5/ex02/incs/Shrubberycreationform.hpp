#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>

#include "../incs/Form.hpp"
#include "../incs/Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private:

		std::string _target;

	public:

		//Coplien
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		//Methode
		void execute(const Bureaucrat& bureaucrat) const;

};

#endif 
