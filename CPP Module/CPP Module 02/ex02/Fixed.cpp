/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:04 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/08 09:07:39 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator = (Fixed const &obj)
{
	this->fixedPointValue = obj.getRawBits();
	return (*this);
}

Fixed Fixed::operator + (Fixed const &obj)
{
	Fixed sum(this->toFloat() + obj.toFloat());
	return (sum);
}

Fixed Fixed::operator - (Fixed const &obj)
{
	Fixed sub(this->toFloat() - obj.toFloat());
	return (sub);
}

Fixed Fixed::operator * (Fixed const &obj)
{
	Fixed mul(this->toFloat() * obj.toFloat());
	return (mul);
}

Fixed Fixed::operator / (Fixed const &obj)
{
	Fixed divi(this->toFloat() / obj.toFloat());
	return (divi);
}

bool Fixed::operator > (Fixed const &obj)
{
	return (fixedPointValue > obj.fixedPointValue);
}

bool Fixed::operator < (Fixed const &obj)
{
	return (fixedPointValue < obj.fixedPointValue);
}

bool Fixed::operator >= (Fixed const &obj)
{
	return (fixedPointValue >= obj.fixedPointValue);	
}

bool Fixed::operator <= (Fixed const &obj)
{
	return (fixedPointValue <= obj.fixedPointValue);
}

bool Fixed::operator == (Fixed const &obj)
{
	return (fixedPointValue == obj.fixedPointValue);	
}

bool Fixed::operator != (Fixed const &obj)
{
	return (fixedPointValue != obj.fixedPointValue);	
}

Fixed Fixed::operator ++ ()
{
	Fixed temp;
	temp.fixedPointValue = ++fixedPointValue;
	return (temp);
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp;
	temp.fixedPointValue = fixedPointValue++;
	return (temp);
}

Fixed Fixed::operator -- ()
{
	Fixed temp;
	temp.fixedPointValue = --fixedPointValue;
	return (temp);
}

Fixed Fixed::operator -- (int)
{
	Fixed temp;
	temp.fixedPointValue = fixedPointValue--;
	return (temp);
}

Fixed Fixed::max(Fixed &obj0, Fixed const &obj1)
{
	if (obj0 >= obj1)
		return (obj0);
	else
		return (obj1);
}

Fixed::Fixed()
{
	fixedPointValue = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &obj)
{
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
	return (fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
	fixedPointValue = raw;
}

Fixed::Fixed(const int inum)
{
	fixedPointValue = (inum << fractionaBits);
	
}

Fixed::Fixed(const float fnum)
{
	fixedPointValue = roundf(fnum * (1 << fractionaBits));
}

float Fixed::toFloat( void ) const
{
	float fnum = ((float)fixedPointValue / (float)(1 << fractionaBits));
	return fnum;
}

int Fixed::toInt( void ) const
{
	int inum = (fixedPointValue >> fractionaBits);
	return inum;	
}

std::ostream &operator << (std::ostream &output, const Fixed &obj)
{
	output << obj.toFloat();
	return (output);
}