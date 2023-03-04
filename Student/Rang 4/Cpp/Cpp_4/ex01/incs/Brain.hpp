#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{

	private:

		std::string _Ideas[100];

	public:

		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& other);

		std::string& idea(int index);

};

#endif
