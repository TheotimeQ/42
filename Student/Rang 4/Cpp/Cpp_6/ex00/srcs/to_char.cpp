#include <iostream>
#include <cstdlib>
#include <climits>

void	to_char(std::string& arg)
{
	try {
		int 	i = std::atoi(arg.c_str());
		double 	d = std::atof(arg.c_str());

		if (arg == "nan" || !(0 <= i && i <= 255.) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
			std::cout << "char   : impossible" << std::endl;
		else if (32 <= i && i <= 126)
			std::cout << "char   : '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char   : Non displayable" << std::endl;
	}
	catch (...) 
	{
		std::cout << "char   : impossible" << std::endl;
	}
}