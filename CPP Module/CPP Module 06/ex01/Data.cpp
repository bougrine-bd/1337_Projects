/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:49:21 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/24 15:10:55 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _C('.'), _I(98), _F(100.05f)
{
}

Data::Data(Data const &obj)
{
    *this = obj;
}

Data &Data::operator = (Data const &obj)
{
    _C = obj._C;
    _I = obj._I;
    _F = obj._F;
    return (*this);
}

Data::~Data()
{
}

char Data::getChar() const
{
    return _C;
}

int Data::getInt() const
{
    return _I;
}

float Data::getFloat() const
{
    return _F;
}