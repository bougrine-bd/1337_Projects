/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:44 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 14:01:14 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    Zombie *Zombie;
    int n = 10;

    Zombie = zombieHorde(n, "zombie");
    for (int i = 0; i < n; i++)
        Zombie[i].announce();
    delete [] Zombie;
}