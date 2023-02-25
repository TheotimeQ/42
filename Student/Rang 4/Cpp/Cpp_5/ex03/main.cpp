#include "bureaucrat.h"
#include "form.h"
#include "intern.h"

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

	Intern intern;

	try
	{
		Form* form = intern.makeForm("PresidentialPardonForm", "random");

		a.signForm(*form);
		form->beSigned(a);
		a.executeForm(*form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
