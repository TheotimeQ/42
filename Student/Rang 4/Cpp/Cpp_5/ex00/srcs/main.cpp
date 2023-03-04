#include "../incs/Bureaucrat.hpp"

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

	Giselle = Christine;
	std::cout << Giselle << std::endl;
	std::cout << Christine << std::endl;

	return 0;
}
