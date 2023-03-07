/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:05:13 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 08:45:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("abdeljalil", 1);
        std::cout << b << std::endl;
        b.decrement();
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}