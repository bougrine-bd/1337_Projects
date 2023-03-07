/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookFoo.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:45:30 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/28 13:13:51 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::add_contact(int i)
{
	std::string frist_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
	std::cout << "Enter First Name: ";
	getline(std::cin, frist_name);
	contacts[i].setFirstName(frist_name);
	std::cout << "Enter Last Name: ";
	getline(std::cin, last_name);
	contacts[i].setLastName(last_name);
	std::cout << "Enter Nickname: ";
	getline(std::cin, nickname);
	contacts[i].setNickname(nickname);
	std::cout << "Enter Phone Number: ";
	getline(std::cin, phone_number);
	contacts[i].setPhoneNumber(phone_number);
	std::cout << "Enter Darkest Secret: ";
	getline(std::cin, darkest_secret);
	contacts[i].setDarkestSecret(darkest_secret);
}

void	PhoneBook::print10(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void	PhoneBook::print_all_info(int i)
{
	std::cout << "First Name: " + contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: " + contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " + contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number: " + contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " + contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::search(int i)
{
	std::string contact_num;
	
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int x = 0; x < i; x++)
	{
			std::cout << std::setw(10);
			std::cout << x + 1;
			std::cout << "|";
			print10(contacts[x].getFirstName());
			std::cout << "|";
			print10(contacts[x].getLastName());
			std::cout << "|";
			print10(contacts[x].getNickname());
			std::cout << "|";
			std::cout << std::endl;
	}
	std::cout << "choose contact: ";
	getline(std::cin, contact_num);
	if (contact_num.length() == 1 && contact_num != "0" && (contact_num[0] - '0') < i + 1)
		print_all_info((contact_num[0] - '0') - 1);
	else
		std::cout << "Invalid input" << std::endl;
}