/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:43:15 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/06 15:22:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedPointValue;
		static const int  fractionaBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &obj);
		Fixed &operator=(Fixed const &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif