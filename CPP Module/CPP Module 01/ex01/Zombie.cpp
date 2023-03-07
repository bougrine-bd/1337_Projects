/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:50 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/04 11:02:37 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << zombieName << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" + zombieName + "> BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getZombieName() const
{
	return (zombieName);
}

void Zombie::setZombieName( std::string name)
{
	zombieName = name;
}