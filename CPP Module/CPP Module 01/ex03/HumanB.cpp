/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:15 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 15:53:51 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name): name(name)
{
}

Weapon HumanB::getWeapon() const
{
    return *weapon;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attacks()
{
    if (weapon)
        std::cout << name << " attacks with his " << weapon->getType() << std::endl;
    else
        std::cout << name << " have no weapon to attacks with " << std::endl;
}