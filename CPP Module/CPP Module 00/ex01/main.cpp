/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:44:28 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/28 13:10:06 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main ()
{
	std::string command;
	PhoneBook phoneBook;
	int i = 0;
	int j = 0;

	while (1)
	{
		std::cout << "Enter command: ";
		getline(std::cin, command);
		if (std::cin.fail())
			break ;
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			phoneBook.add_contact(i);
			if (j < 8)
				j++;
			if (i < 7)
				i++;
			else if (i == 7)
				i = 0;
		}
		else if (command == "SEARCH")
			phoneBook.search(j);
	}
}