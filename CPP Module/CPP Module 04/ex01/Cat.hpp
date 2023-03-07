/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:11:52 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/12 17:27:31 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const &cat);
		Cat &operator = (Cat const &cat);
		~Cat();

        std::string getType() const;
        Brain *getBrain() const;
		void makeSound() const;
};

#endif