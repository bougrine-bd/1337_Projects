/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:43:15 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/06 15:30:37 by abougrin         ###   ########.fr       */
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
		Fixed(const int inum);
		Fixed(const float fnum);
		~Fixed();

		Fixed(Fixed const &obj);

		Fixed &operator = (Fixed const &obj);
		Fixed operator + (Fixed const &obj);
		Fixed operator - (Fixed const &obj);
		Fixed operator * (Fixed const &obj);
		Fixed operator / (Fixed const &obj);
		
		bool operator > (Fixed const &obj);
		bool operator < (Fixed const &obj);
		bool operator >= (Fixed const &obj);
		bool operator <= (Fixed const &obj);
		bool operator == (Fixed const &obj);
		bool operator != (Fixed const &obj);

		Fixed operator ++ ();
		Fixed operator ++ (int);
		Fixed operator -- ();
		Fixed operator -- (int);

		static Fixed max(Fixed &obj0, Fixed const &obj1);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator << (std::ostream &output, const Fixed &obj);

#endif