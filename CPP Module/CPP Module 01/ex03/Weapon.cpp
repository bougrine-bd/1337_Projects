/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:30 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 15:45:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : type(type)
{
}

std::string& Weapon::getType() 
{
    return type;
}

void Weapon::setType( std::string strREF)
{
    type = strREF;
}