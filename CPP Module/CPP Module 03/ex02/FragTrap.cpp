/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:13:48 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/10 16:35:21 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_name = "(No Name)";
	_hitpoint = 100;
	_energyPoint = 100;
	_attackDamage = (30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hitpoint = 100;
	_energyPoint = 100;
	_attackDamage = (30);
}

FragTrap::FragTrap(FragTrap const &obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = obj;
}

FragTrap &FragTrap::operator = (FragTrap const &obj)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	_name = obj._name;
	_hitpoint = obj._hitpoint;
	_energyPoint = obj._energyPoint;
	_attackDamage = obj._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap distructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "Give me High fives!" << std::endl;
}