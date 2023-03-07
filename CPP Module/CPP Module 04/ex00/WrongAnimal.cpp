/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:02:05 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/08 13:15:15 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal costructor called" << std::endl;    
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal)
{
    std::cout << "WrongAnimal copy costructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator = (WrongAnimal const &wrongAnimal)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    type = wrongAnimal.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "No Sound" << std::endl;    
}