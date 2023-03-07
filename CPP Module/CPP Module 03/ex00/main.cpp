/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:36:16 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/10 16:26:36 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap player1("Mr.Qdoor");
	ClapTrap player2("Ms.Qdoora");

	player1.attack(player2.getName());
	player2.takeDamage(10);
	player2.beRepaired(5);
	
	return (0);
}