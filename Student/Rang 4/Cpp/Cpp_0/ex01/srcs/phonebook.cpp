/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:57:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/01 16:32:13 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/contact.hpp"
#include "../incs/phonebook.hpp"

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
	return this->cts[index];
}

void Phonebook::Add_Contact(Contact contact)
{
	this->cts[this->index] = contact;
	this->index = (this->index + 1) % 8;
	if (nb <= 8)
		this->nb++; 
	return;
}
