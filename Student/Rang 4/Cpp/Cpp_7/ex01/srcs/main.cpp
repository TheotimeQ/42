#include <iostream>
#include "../incs/iter.hpp"

int main()
{
	int int_tab[10] = {0,1,2,3,4,5,6,7,8,9};
	iter(int_tab, 10, print);
	std::cout << std::endl;

	std::string string_tab[3] = {"J'adore","les","poneys"};
	iter(string_tab, 3, print);
	std::cout << std::endl;

	return 0;
}
