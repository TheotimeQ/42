#include "../incs/Data.hpp"

Data::Data(int integer, const std::string& string, float floating) :
	_Integer(integer),
	_String(string),
	_Floating(floating)
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

//------------Getters--------------
int Data::integer() const
{
	return _Integer;
}

std::string Data::string() const
{
	return _String;
}

float Data::floating() const
{
	return _Floating;
}

//-----------Setters----------------
void Data::setInteger(int newInteger)
{
	_Integer = newInteger;
}

void Data::setString(const std::string& newString)
{
	_String = newString;
}

void Data::setFloating(float newFloating)
{
	_Floating = newFloating;
}

//-----------Other-------------------
std::ostream& operator<<(std::ostream& out, const Data& data)
{
	out << "integer: " << data.integer()
		<< ", string: " << data.string()
		<< ", floating: " << data.floating();
	return out;
}
