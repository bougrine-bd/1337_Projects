/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:11:46 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/07 18:29:37 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat costructor called" << std::endl;    
    type = "Cat";
}

Cat::Cat(Cat const &cat)
{
    std::cout << "Cat copy costructor called" << std::endl;
    *this = cat; 
}

Cat &Cat::operator = (Cat const &cat)
{
    std::cout << "Cat assignment operator called" << std::endl;
    type = cat.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const
{
    return (type);
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl; 
}