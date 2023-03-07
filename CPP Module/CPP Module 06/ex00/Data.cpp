/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:04:10 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/24 16:47:49 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
}

Data::Data(std::string str)
{
	_str = str;
}

Data::Data(Data const &obj)
{
	*this = obj;
}

Data &Data::operator = (Data const &obj)
{
	_str = obj._str;
	return (*this);
}

Data::~Data()
{
}

Data::operator char() const
{
	char C;
	try
	{
		int i = std::stoi(_str);
		C = static_cast<char>(i);
		if (isprint(C))
			std::cout << "char: '" << C << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	catch (const std::exception& e)
	{
		if (_str.length() == 1)
		{
			C = static_cast<char>(_str[0]);
			std::cout << "char: '" << _str[0] << "'\n";
		}
		else
			std::cout << "char: impossible\n";
	}
	return (C);
}

Data::operator int() const
{
	int I;
	try
	{
		I = static_cast<int>(std::stoi(_str));
		std::cout << "int: " << I << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible\n";
	}
	return (I);
}

Data::operator float() const
{
	float F;
	try
	{
		F = static_cast<float>(std::stof(_str));
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << F << "f\n";   
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible\n";
	}
	return (F);
}

Data::operator double() const
{
	double D;
	try
	{
		D = static_cast<double>(std::stod(_str));
		std::cout.precision(1);
		std::cout << "double: " << std::fixed << D << std::endl;   
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible\n";
	}
	return (D);
}

void Data::doAllWork()
{
	char C = static_cast<char>(*this);
	C++;
	int I = static_cast<int>(*this);
	I++;
	float F = static_cast<float>(*this);
	F++;
	double D = static_cast<double>(*this);
	D++;
}
