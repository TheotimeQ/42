#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "form.h"
#include "bureaucrat.h"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& bureaucrat) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

private:
	std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_H
