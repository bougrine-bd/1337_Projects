/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:53:01 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/03 10:53:02 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address in memory of the string: "<< &str << std::endl;
    std::cout << "Address of the string by using stringPTR: "<< stringPTR << std::endl;
    std::cout << "Address of the string by using stringREF: "<< &stringREF << std::endl;
    std::cout << "String by using stringPTR: "<< *stringPTR << std::endl;
    std::cout << "String by using stringREF: "<< stringREF << std::endl;
}