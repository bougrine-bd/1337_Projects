/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactFoo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:44:24 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/27 17:46:16 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::getFirstName( void )
{
	return (_FristName);
}
std::string Contact::getLastName( void )
{
	return (_LastName);
}
std::string Contact::getNickname( void )
{
	return (_Nickname);
}
std::string Contact::getPhoneNumber( void )
{
	return (_PhoneNumber);
}
std::string Contact::getDarkestSecret( void )
{
	return (_DarkestSecret);
}

void Contact::setFirstName(std::string first_name)
{
	_FristName = first_name;
}

void Contact::setLastName(std::string last_name)
{
	_LastName = last_name;
}

void Contact::setNickname(std::string nickname)
{
	_Nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	_PhoneNumber = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	_DarkestSecret = darkest_secret;
}