/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:33 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/14 11:38:41 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constractor called" << std::endl;
}

Brain::Brain(Brain const &brain)
{
	std::cout << "Brain copy constractor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator = (Brain const &brain)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain distractor called" << std::endl;
}

std::string *Brain::getIdeas()
{
	return (ideas);
}

void Brain::setIdeas(std::string idea, int i)
{
	ideas[i] = idea;
}
