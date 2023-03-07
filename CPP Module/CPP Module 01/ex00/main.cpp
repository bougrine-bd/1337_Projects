/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:16 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 11:40:08 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main ()
{
	Zombie *zb;
	Zombie *zb1;

	zb = newZombie("zombie 0");
	zb->announce();
	
	zb1 = newZombie("zombie 1");
	zb1->announce();
	
	randomChump("zombie 2");
	
	delete zb;
	delete zb1;
}