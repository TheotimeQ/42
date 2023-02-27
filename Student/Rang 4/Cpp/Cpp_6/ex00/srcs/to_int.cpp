#include <iostream>
#include <cstdlib>
#include <climits>

void	to_int(std::string& arg)
{
	try 
	{	
		int 	i = std::atoi(arg.c_str());
		double 	d = std::atof(arg.c_str());

		if (arg == "nan" || d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
			std::cout << "int    : impossible" << std::endl;
		else
			std::cout << "int    : " << i << std::endl;
	}
	catch (...) 
	{
		std::cout << "int    : impossible" << std::endl;
	}
}