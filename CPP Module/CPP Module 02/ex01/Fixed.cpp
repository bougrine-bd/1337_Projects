/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:04 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/08 09:02:30 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator = (Fixed const &obj)
{
	std::cout << "assignment operator called" << std::endl;
	this->fixedPointValue = obj.getRawBits();
	return (*this);
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
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = (inum << fractionaBits);
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << std::endl;
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
	float num = obj.toFloat();
	output << num;
	return (output);
}