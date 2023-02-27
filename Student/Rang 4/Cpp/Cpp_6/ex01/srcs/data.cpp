#include "data.h"

Data::Data(int integer, const std::string& string, float floating) :
	_integer(integer),
	_string(string),
	_floating(floating)
{
}

uintptr_t Data::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Data::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int Data::integer() const
{
	return _integer;
}

void Data::setInteger(int newInteger)
{
	_integer = newInteger;
}

std::string Data::string() const
{
	return _string;
}

void Data::setString(const std::string& newString)
{
	_string = newString;
}

float Data::floating() const
{
	return _floating;
}

void Data::setFloating(float newFloating)
{
	_floating = newFloating;
}

std::ostream& operator<<(std::ostream& out, const Data& data)
{
	out << "integer: " << data.integer()
		<< ", string: " << data.string()
		<< ", floating: " << data.floating();
	return out;
}
