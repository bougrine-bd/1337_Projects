/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:02:11 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/08 13:11:58 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(WrongCat const &wrongCat);
		WrongCat &operator = (WrongCat const &wrongCat);
		~WrongCat();

		std::string getType() const;
		void makeSound() const;
};

#endif