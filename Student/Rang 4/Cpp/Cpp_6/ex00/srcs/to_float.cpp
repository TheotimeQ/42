#include <iostream>
#include <cstdlib>
#include <climits>

void	to_float(std::string& arg)
{
	try {
		double d = std::atof(arg.c_str());
		float f = static_cast<float>(d);

		std::cout << "float  : " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	} 
	catch (...) 
	{
		std::cout << "float  : impossible" << std::endl;
	}
}