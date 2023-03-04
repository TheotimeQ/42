#include "../incs/Data.hpp"

Data::Data(int int_, const std::string& str_, float float_, void* void_, char char_):
	_str(str_),
	_int(int_),
	_float(float_),
	_void(void_),
	_char(char_)
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
int Data::Get_int() const
{
	return _int;
}

std::string Data::Get_str() const
{
	return _str;
}

float Data::Get_float() const
{
	return _float;
}

void* Data::Get_void() const
{
	return _void;
}

char Data::Get_char() const
{
	return _char;
}

//-----------Other-------------------
std::ostream& operator<<(std::ostream& out, const Data& data)
{
	out << "int       : " << data.Get_int() << std::endl;
	out << "string    : " << data.Get_str() << std::endl;
	out << "floating  : " << data.Get_float() << std::endl;
	out << "void      : " << data.Get_void() << std::endl;
	out << "char*     : " << data.Get_char() << std::endl;
	return out;
}
