/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:36:24 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/10 15:25:28 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("(No Name)"), _hitpoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator = (ClapTrap const &obj)
{
	std::cout << "assignment operator called" << std::endl;
	_name = obj._name;
	_hitpoint = obj._hitpoint;
	_energyPoint = obj._energyPoint;
	_attackDamage = obj._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "distructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getHitpoint() const
{
	return (_hitpoint);
}

int ClapTrap::getEnergyPoint() const
{
	return (_energyPoint);
}

int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << ", take " << amount << " point of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << ", be repaired " << amount << " point of energy." << std::endl;
}