/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:41:55 by zelinsta          #+#    #+#             */
/*   Updated: 2023/01/30 15:45:17 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

std::string Contact::getNickName() const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::getSecret() const
{
	return this->_secret;
}

void Contact::setFirstName(std::string name)
{
	this->_firstName = name;
	return;
}

void Contact::setLastName(std::string name)
{
	this->_lastName = name;
	return;
}

void Contact::setNickName(std::string name)
{
	this->_nickName = name;
	return;
}

void Contact::setPhoneNumber(std::string number)
{
	this->_phoneNumber = number;
	return;
}

void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
	return;
}