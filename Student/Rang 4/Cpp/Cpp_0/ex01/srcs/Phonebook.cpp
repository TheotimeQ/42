#include "../incs/Contact.hpp"
#include "../incs/Phonebook.hpp"

Phonebook::Phonebook() : index(0), nb(0)
{
	return;
}

Phonebook::Phonebook(const Phonebook &src)
{
	for (int i = 0; i < src.nb; i++)
        cts[i] = src.cts[i];
    index = src.index;
    nb = src.nb;
}

Phonebook& Phonebook::operator=(const Phonebook& other)
{
	if (this != &other) {
		this->index = other.index;
		this->nb = other.nb;
		for (int i = 0; i < MAX_CTS; i++) 
        	this->cts[i] = other.cts[i];
	}
	return *this;
}

Phonebook::~Phonebook()
{
	return;
}

Contact Phonebook::Get_Contact(int index) const
{
	return (this->cts[index]);
}

int Phonebook::Get_Nb(void) const
{
	return (this->nb);
}

void Phonebook::Add_Contact(Contact contact)
{
	this->cts[this->index] = contact;
	this->index = (this->index + 1) % MAX_CTS;
	if (nb < MAX_CTS)
		this->nb++; 
	return;
}
