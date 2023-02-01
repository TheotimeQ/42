/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:57:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/01/30 15:45:14 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/phonebook.hpp"

Phonebook::Phonebook()
: _index(0)
{
	return;
}

Phonebook::~Phonebook()
{
	return;
}

Contact Phonebook::getContact(int index) const
{
	return this->_contacts[index];
}

int	Phonebook::getCount() const
{
	return this->_count;
}

void Phonebook::setContact(Contact contact)
{
	this->_contacts[this->_index] = contact;
	_count = (_count < 8) ? _count + 1 : _count;
	this->_index = (this->_index + 1) % 8;
	return;
}

int Phonebook::_count = 0;