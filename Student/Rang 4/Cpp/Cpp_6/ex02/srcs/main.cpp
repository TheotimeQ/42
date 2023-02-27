#include <iostream>
#include "a.h"
#include "b.h"
#include "c.h"

Base* generate()
{
	switch (rand() % 3)
	{
	case 0: return new A; break;
	case 1: return new B; break;
	case 2: return new C; break;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	return ;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (...) { }
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch (...) { }
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch (...) { }
}

int main()
{
	std::srand(std::time(NULL));

	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);

	return 0;
}
