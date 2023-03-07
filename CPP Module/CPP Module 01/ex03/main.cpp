/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:22 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 15:26:51 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main ()
{
	{
		Weapon club = Weapon("pump");
		HumanA bd("bougrine", club);
		bd.attacks();
		club.setType("double pump");
		bd.attacks();
	}
	{
		Weapon club = Weapon("water gun");
		HumanB ouk("amin");
		ouk.setWeapon(club);
		ouk.attacks();
		club.setType("hand");
		ouk.attacks();
	}
}