#include <iostream>

#include "../incs/Fixed.hpp"

const int Fixed::Nb_Bit_Fract = 8;

Fixed::Fixed() : Nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Nb);
}

void Fixed::setRawBits(const int Nb)
{
	this->Nb = Nb;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator function called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}
