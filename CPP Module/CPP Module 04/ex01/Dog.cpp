/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:11:55 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/12 17:30:01 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    std::cout << "Dog costructor called" << std::endl;
    type = "Dog";  
}

Dog::Dog(Dog const &dog) : brain(new Brain())
{
    std::cout << "Dog copy costructor called" << std::endl;
    *this = dog;  
}

Dog &Dog::operator = (Dog const &dog)
{
    std::cout << "Dog assignment operator called" << std::endl;
    type = dog.type;
    *brain = *dog.brain;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

std::string Dog::getType() const
{
    return type;
}

Brain *Dog::getBrain() const
{
    return (brain);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl; 
}