#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
    std::cout << std::endl;
    
	std::cout << "Address string      : " << &string << std::endl;
	std::cout << "Adress in stringPTR : " << stringPTR << std::endl;
	std::cout << "Adress in stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;

	std::cout << "Value of string            : " << string << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl;
    std::cout << std::endl;
}

