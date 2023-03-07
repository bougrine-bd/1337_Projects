/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:02:09 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/08 13:15:38 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat costructor called" << std::endl;    
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &wrongCat)
{
    std::cout << "WrongCat copy costructor called" << std::endl;
    *this = wrongCat; 
}

WrongCat &WrongCat::operator = (WrongCat const &wrongCat)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    type = wrongCat.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
    return (type);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Meow Meow" << std::endl; 
}