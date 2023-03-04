#include <iostream>
#include <cstdlib>
#include <climits>

void	to_double(std::string& arg)
{
	try 
	{
		double d = std::atof(arg.c_str());
		std::cout << "double : " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << std::endl;
	} 
	catch (...) 
	{
		std::cout << "double : impossible" << std::endl;
	}
}