#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>

#include "../incs/Form.hpp"
#include "../incs/Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private:

		std::string _target;

	public:

		//Coplien
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		//Methodes
		void execute(const Bureaucrat& bureaucrat) const;

};

#endif
