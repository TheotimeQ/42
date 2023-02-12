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
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->Nb = value << this->Nb_Bit_Fract;
}

//Construit le float
Fixed::Fixed(const float value)
{	
	std::cout << "Float constructor called" << std::endl;

	//Recupere la partie entiere et decale de Nb bit pour laisser la place au float
	this->Nb = static_cast<int>(value) << this->Nb_Bit_Fract;

	//Construit la partie floatante
	float	float_part = value - toInt();

	//Construit le mask
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
	std::cout << "Copy assignment operator function called" << std::endl;
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

//Recupere la partie entiere , puis ajoute la partie decimal bit apres bit
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

//Decale de 8 bit vers la droite pour detruite la partie à virgule
int Fixed::toInt() const
{
	return (this->Nb >> this->Nb_Bit_Fract);
}

//Affiche la class fixed
//std::cout << f << std::endl;
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (out);
}
