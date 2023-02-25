#include "bureaucrat.h"
#include "form.h"
#include "shrubberycreationform.h"
#include "robotomyrequestform.h"
#include "presidentialpardonform.h"

int main()
{
	try
	{
		Bureaucrat test("test", 0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	try
	{
		a.increment();
		b.decrement();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	try
	{
		ShrubberyCreationForm form("hey");

		a.signForm(form);
		form.beSigned(a);
		a.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		ShrubberyCreationForm form("shrubbery");

		a.signForm(form);
		form.beSigned(a);
		a.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		RobotomyRequestForm form("robotomy");

		a.signForm(form);
		form.beSigned(a);
		a.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		PresidentialPardonForm form("pardon");

		a.signForm(form);
		form.beSigned(a);
		a.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
