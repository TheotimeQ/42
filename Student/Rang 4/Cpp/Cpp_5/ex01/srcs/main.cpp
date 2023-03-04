#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

int main()
{
	try {
		Bureaucrat Jerem("Jeremie de la compta", 0);
		std::cout << Jerem << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat Christine("Christine du secretariat", 1);
	std::cout << Christine << std::endl;
	try
	{
		Christine.increment();
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Christine.decrement();
	std::cout << Christine << std::endl;

	Bureaucrat Giselle("Giselle de la logistique", 150);
	std::cout << Giselle << std::endl;
	try
	{
		Giselle.decrement();
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Giselle.increment();
	std::cout << Giselle << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Form Form_1("Form_1", 50, 50);
	Form Form_2("Form_2", 100, 100);
	Form Form_3(Form_2);

	try
	{
		Christine.signForm(Form_1);
		Christine.signForm(Form_1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Giselle.signForm(Form_2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form_2.beSigned(Giselle);
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
