/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:43:15 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/06 10:39:47 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPointValue;
		static const int  fractionaBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &obj);
		Fixed &operator = (Fixed const &obj);
		Fixed(const int inum);
		Fixed(const float fnum);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator << (std::ostream &output, const Fixed &obj);

#endif