/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:08 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 15:50:50 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon ) : name(name), weapon(weapon)
{
}

void HumanA::attacks( void )
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}