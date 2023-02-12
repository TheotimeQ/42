/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:30:51 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/12 15:03:23 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{

    private:

	    int                 Nb;
	    static const int    Nb_Bit_Fract;
    
    public:

        //Constructeur par default
        Fixed();

        //Constructeur par copie
        Fixed(const Fixed& other);
    	Fixed(const int value);
    	Fixed(const float value);

        //Operateur d'affectation
        Fixed& operator=(const Fixed& other);

        //Destructeur
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    	float   toFloat() const;
    	int     toInt() const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif