/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:42:14 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/27 17:47:37 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string _FristName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
	public:
		std::string getFirstName( void );
		std::string getLastName( void );
		std::string getNickname( void );
		std::string getPhoneNumber( void );
		std::string getDarkestSecret( void );
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phone_number);
		void setDarkestSecret(std::string darkest_secret);
};

#endif