/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:49:23 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/24 13:33:49 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		char _C;
		int _I;
		float _F;
	public:
		Data();
		Data(Data const &obj);
		Data &operator = (Data const &obj);
		~Data();

		char getChar() const;
		int getInt() const;
		float getFloat() const;
};

#endif