#include <iostream>
#include "data.h"

int main()
{
	Data orig(42, "HEY!", 9.81f);

	uintptr_t serialized = Data::serialize(&orig);
	Data* deserialized = Data::deserialize(serialized);

	std::cout << orig << std::endl;
	std::cout << *deserialized << std::endl;
	std::cout << &orig << std::endl;
	std::cout << deserialized << std::endl;

	return 0;
}
