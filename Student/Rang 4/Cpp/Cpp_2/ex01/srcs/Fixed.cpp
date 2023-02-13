/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:30:54 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/12 16:27:10 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int Fixed::Nb_Bit_Fract = 8;

Fixed::Fixed()
{
	this->Nb = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->Nb = value << this->Nb_Bit_Fract;
}

Fixed::Fixed(const float value)
{	
	std::cout << "Float constructor called" << std::endl;
	this->Nb = static_cast<int>(value) << this->Nb_Bit_Fract;
	float	float_part = value - toInt();
	int 	mask = 1 << (this->Nb_Bit_Fract - 1);
	float 	power_two;
	int		i = 2;

	while (mask)
	{
		power_two = 1.0f / static_cast<float>(i);
		
		if(float_part > power_two)
		{
			float_part -= power_two;
			this->Nb |= mask;
		}
		
		mask = mask >> 1;
		i = i << 1;
	}
	power_two = 1.0f / static_cast<float>(i);
	if(float_part > power_two / 2)
		this->Nb++;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->Nb);
}

void Fixed::setRawBits(const int Nb)
{
	this->Nb = Nb;
}

float Fixed::toFloat() const
{
	float 		float_build = toInt();
	int 		mask = 1 << (this->Nb_Bit_Fract - 1);
	float 		power_two;
	int			i = 2;

	while (mask)
	{
		power_two = 1.0f / static_cast<float>(i);
	
		if(this->Nb & mask)
			float_build += power_two;

		mask = mask >> 1;
		i = i << 1;
	}
	return (float_build);
}

int Fixed::toInt() const
{
	return (this->Nb >> this->Nb_Bit_Fract);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (out);
}
