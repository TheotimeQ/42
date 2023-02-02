/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:57:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/02 08:19:09 by zelinsta         ###   ########.fr       */
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
// Phonebook::Phonebook(const Phonebook&)
// {
// 	return;
// }

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
	this->index = (this->index + 1) % 8;
	if (nb <= 8)
		this->nb++; 
	return;
}
