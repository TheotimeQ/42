#include <iostream>

#include "../incs/Data.hpp"

int main()
{
	Data My_Data(42, "42!", 42.0f, (void*)42, '4');

	uintptr_t serialized = Data::serialize(&My_Data);
	Data* deserialized = Data::deserialize(serialized);

	std::cout << My_Data << std::endl;
	std::cout << *deserialized << std::endl;

	std::cout << &My_Data << std::endl;
	std::cout << deserialized << std::endl;

	return 0;
}

