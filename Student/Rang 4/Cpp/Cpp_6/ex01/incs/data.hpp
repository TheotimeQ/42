#ifndef DATA_H
#define DATA_H

#include <cstdint>
#include <string>
#include <iostream>

class Data
{
public:
	Data(int integer, const std::string& string, float floating);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	int integer() const;
	std::string string() const;
	float floating() const;

	void setInteger(int newInteger);
	void setString(const std::string& newString);
	void setFloating(float newFloating);

private:
	int	_integer;
	std::string _string;
	float _floating;
};

std::ostream& operator<<(std::ostream& out, const Data& data);

#endif // DATA_H
