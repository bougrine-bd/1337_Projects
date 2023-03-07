/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:06:53 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/24 15:52:52 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string _str;
		Data();
	public:
		Data(std::string str);
		Data(Data const &obj);
		Data &operator = (Data const &obj);
		~Data();

		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

		void doAllWork();
};

#endif