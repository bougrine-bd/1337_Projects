/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:36:12 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/10 16:33:42 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_name = "(No Name)";
	_hitpoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hitpoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap &ScavTrap::operator = (ScavTrap const &obj)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	_name = obj._name;
	_hitpoint = obj._hitpoint;
	_energyPoint = obj._energyPoint;
	_attackDamage = obj._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap distructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterredin Gate" << std::endl;
}