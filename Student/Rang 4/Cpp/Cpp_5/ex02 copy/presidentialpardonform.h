#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <string>
#include "bureaucrat.h"
#include "form.h"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& bureaucrat) const;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

private:
	std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_H
