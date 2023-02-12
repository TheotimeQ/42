/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:57:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/03 10:02:13 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"
#include "../incs/Phonebook.hpp"

// Constructeur par défaut
Phonebook::Phonebook() : index(0), nb(0)
{
	return;
}

// Constructeur de recopie
Phonebook::Phonebook(const Phonebook &src)
{
	for (int i = 0; i < src.nb; i++)
        cts[i] = src.cts[i];
    index = src.index;
    nb = src.nb;
}

// Operateur d'affectation
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

// Destructeur
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
