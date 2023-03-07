/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:44:04 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/27 11:44:10 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int  main (int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            std::string argvs = argv[i];
            for (int j = 0; argvs[j]; j++)
                std::cout << (char)toupper(argvs[j]);
        }
    }
    std::cout << std::endl;
    return (0);
}