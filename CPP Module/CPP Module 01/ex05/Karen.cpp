/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:53 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/04 12:47:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen::debug( void )
{
	std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info( void )
{
	std::cout << "I cannot believe adding extrabacon cost more money. You don’t put enough! If you did I would not have to askfor it!" << std::endl;
}

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve beencoming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
{
	std::string levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*ptmf[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

    for (int i = 0; i < 4; i++)
    {
        if (levelList[i] == level)
        {
            (this->*ptmf[i])();
            return ;
        }
    }
    std::cout << "--there's no level--" << std::endl;
}