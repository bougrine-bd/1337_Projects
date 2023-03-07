/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:56 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 13:46:12 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		ZombieHorde[i].setZombieName(name);
	return (ZombieHorde);
}