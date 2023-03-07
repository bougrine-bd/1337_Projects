/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:53:01 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/12 18:08:36 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal const &animal);
		Animal &operator = (Animal const &animal);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif