#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <string>

#include "../incs/Form.hpp"
#include "../incs/Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	private:
		
		std::string _target;

	public:
		
		//Coplien
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		//Methode
		void execute(const Bureaucrat& bureaucrat) const;


};

#endif
