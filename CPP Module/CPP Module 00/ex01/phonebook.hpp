/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:41:41 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/28 13:14:08 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		void add_contact(int i);
		void print10(std::string str);
		void print_all_info(int i);
		void search(int i);
};

#endif