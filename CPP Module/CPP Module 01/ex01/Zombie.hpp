/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:52:53 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 14:01:40 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string zombieName;
    public:
        Zombie();
        ~Zombie();
        void announce();
        std::string getZombieName() const;
        void setZombieName( std::string zombieName);
};

#endif