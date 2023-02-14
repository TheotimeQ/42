#include <string>

#include "../incs/Contact.hpp"

Contact::Contact()
{
	return;
}

Contact::Contact(const Contact &src) 
{
    First_Name = src.First_Name;
    Last_Name = src.Last_Name;
    Nick_Name = src.Nick_Name;
    Phone_Number = src.Phone_Number;
    Secret = src.Secret;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other) {
		this->First_Name = other.First_Name;
		this->Last_Name = other.Last_Name;
		this->Nick_Name = other.Nick_Name;
		this->Phone_Number = other.Phone_Number;
		this->Secret = other.Secret;
	}
	return *this;
}

Contact::~Contact()
{
	return;
}

std::string Contact::Get_First_Name()	const
{
	return (this->First_Name);
}

std::string Contact::Get_Last_Name() 	const
{
	return (this->Last_Name);
}

std::string Contact::Get_Nick_Name() 	const
{
	return (this->Nick_Name);
}

std::string	Contact::Get_Phone_Number() 	const
{
	return (this->Phone_Number);
}

std::string Contact::Get_Secret() 		const
{
	return (this->Secret);
}

void Contact::Set_First_Name(std::string str)
{
	this->First_Name = str;
	return;
}

void Contact::Set_Last_Name(std::string str)
{
	this->Last_Name = str;
	return;
}

void Contact::Set_Nick_Name(std::string str)
{
	this->Nick_Name = str;
	return;
}

void Contact::Set_Phone_Number(std::string str)
{
	this->Phone_Number = str;
	return;
}

void Contact::Set_Secret(std::string str)
{
	this->Secret = str;
	return;
}
