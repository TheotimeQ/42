#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{

    private:

	    int                 Nb;
	    static const int    Nb_Bit_Fract;
    
    public:

        Fixed();
        Fixed(const Fixed& other);
    	Fixed(const int value);
    	Fixed(const float value);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    	float   toFloat() const;
    	int     toInt() const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif