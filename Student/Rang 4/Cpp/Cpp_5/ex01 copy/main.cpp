#include "bureaucrat.h"
#include "form.h"

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

	Form form("form", 50, 50);

	try
	{
		a.signForm(form);
		form.beSigned(a);
		b.signForm(form);
		form.beSigned(b);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
