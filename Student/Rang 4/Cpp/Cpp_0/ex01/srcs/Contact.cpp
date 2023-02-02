/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:41:55 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/02 08:18:55 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

// Constructeur par défaut
Contact::Contact()
{
	return;
}

// Constructeur de recopie
// Contact::Contact(const Contact&)
// {
// 	return;
// }

// Destructeur
Contact::~Contact()
{
	return;
}

// Get
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

//Set
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