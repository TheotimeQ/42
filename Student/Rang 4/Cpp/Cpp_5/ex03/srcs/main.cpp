#include "../incs/Bureaucrat.hpp"
#include "../incs/Intern.hpp"
#include "../incs/Form.hpp"
#include "../incs/Shrubberycreationform.hpp"
#include "../incs/Robotomyrequestform.hpp"
#include "../incs/Presidentialpardonform.hpp"

int main()
{
	//Bureaucrate
	Bureaucrat Jerem("Jeremie the slavemaster", 1);
	std::cout << Jerem << std::endl;
	std::cout << std::endl;

	Intern Tristan;

	try
	{
		Form* form = Tristan.makeForm("ShrubberyCreationForm", "Bender");
		Jerem.signForm(*form);
		Jerem.executeForm(*form);

		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
