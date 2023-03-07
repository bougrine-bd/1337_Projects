/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:33 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 15:39:02 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	zombieName = name;
}

Zombie::~Zombie()
{
	std::cout << zombieName << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" << zombieName << "> BraiiiiiiinnnzzzZ..." << std::endl;
}