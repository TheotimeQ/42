#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"
#include "../incs/Shrubberycreationform.hpp"
#include "../incs/Robotomyrequestform.hpp"
#include "../incs/Presidentialpardonform.hpp"

int main()
{
	//Bureaucrate
	Bureaucrat Jerem("Jeremie de la compta", 5);
	std::cout << Jerem << std::endl;
	std::cout << std::endl;

	//Test form Pardon
	try
	{
		PresidentialPardonForm form("Pardon");
		Jerem.signForm(form);
		Jerem.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//Test form shrubbery
	try
	{
		ShrubberyCreationForm form("shrubbery");
		Jerem.signForm(form);
		Jerem.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//Test form robotomy
	try
	{
		RobotomyRequestForm form("robotomy");
		Jerem.signForm(form);
		//Form alrdy signed
		Jerem.signForm(form);
		Jerem.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//-----------------------Test error--------------------------

	try
	{
		Bureaucrat Noobish("Noobish du placard", 150);
		std::cout << Noobish << std::endl;
		
		//Form not signed
		RobotomyRequestForm form("robotomy");
		Noobish.executeForm(form);
		std::cout << std::endl;

		//Can't sign form
		Noobish.signForm(form);
		std::cout << std::endl;

		//Low grade to execute
		Jerem.signForm(form);
		Noobish.executeForm(form);
		std::cout << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}







	return 0;
}
