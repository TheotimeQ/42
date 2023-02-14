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

        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        ~Fixed();

        int                 getRawBits(void) const;
        void                setRawBits(int const raw);
    	float               toFloat() const;
    	int                 toInt() const;
        static Fixed&       max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
        static Fixed&       min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif