/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:52:58 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/14 11:36:22 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal costructor called" << std::endl;
}

Animal::Animal(Animal const &animal)
{
    std::cout << "Animal copy costructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator = (Animal const &animal)
{
    std::cout << "Animal assignment operator called" << std::endl;
    type = animal.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "No Sound" << std::endl;    
}
