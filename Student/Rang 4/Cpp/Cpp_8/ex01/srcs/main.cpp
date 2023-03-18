#include <iostream>
#include <vector>

#include "../incs/Span.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(70);
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);

	Span sp = Span(6);

	sp.addNumbers(vec.begin(), vec.end());
	sp.addNumber(45);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp_2(sp);
	std::cout << sp_2.shortestSpan() << std::endl;
	std::cout << sp_2.longestSpan() << std::endl;

	//Exception Full: 
	try{
		sp.addNumber(10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//Exception NotEnough
	Span sp_ex = Span(3);

	try{
		std::cout << sp_ex.shortestSpan() << std::endl;
		std::cout << sp_ex.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	sp_ex.addNumber(10);
	try{
		std::cout << sp_ex.shortestSpan() << std::endl;
		std::cout << sp_ex.longestSpan() << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
