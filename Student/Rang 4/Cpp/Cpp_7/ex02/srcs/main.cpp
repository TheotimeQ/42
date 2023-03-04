#include <iostream>

#include "../incs/Array.hpp"

int main()
{

	{
		// Array d'int
		Array<int> int_tab(3);
		int_tab[0] = 42;
		int_tab[1] = 101;
		int_tab[2] = 21;
		std::cout << int_tab << std::endl;

		Array<int> int_tab_cpy(int_tab);
		std::cout << int_tab_cpy << std::endl;

		int_tab[1] = 0;
		std::cout << int_tab << std::endl;
		std::cout << int_tab_cpy << std::endl;

		//Exception
		try{int_tab[10] = 0;}
		catch (std::exception& e){std::cout << e.what() << std::endl;}

		try{int_tab[-5] = 0;}
		catch (std::exception& e){std::cout << e.what() << std::endl;}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	{
		//Array de string
		Array<std::string> str_tab(3);
		str_tab[0] = "J'aime";
		str_tab[1] = "les";
		str_tab[2] = "poneys";
		std::cout << str_tab << std::endl;

		Array<std::string> str_tab_cpy(str_tab);
		std::cout << str_tab_cpy << std::endl;

		str_tab[2] = "chat";
		std::cout << str_tab << std::endl;
		std::cout << str_tab_cpy << std::endl;

		//Exception
		try{str_tab[10] = "truc";}
		catch (std::exception& e){std::cout << e.what() << std::endl;}

		try{str_tab[-5] = "machin";}
		catch (std::exception& e){std::cout << e.what() << std::endl;}
	}





	return 0;
}
