/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:08:12 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/14 11:29:42 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int num = 6;
	const Animal *animal[num];
	for(int i=0; i < num; i++)
	{
		if (i < num / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < num; i++)
	{
		std::cout << animal[i]->getType() << " : ";
		animal[i]->makeSound();
	}
	for(int i = 0; i < num; i++)
		delete animal[i];

	std::cout << std::endl;

	Cat *catptr = new Cat();
	for (int i =0; i < 100; i++)
	{
		catptr->getBrain()->setIdeas("cat brain", i);
	}
	
	{
		Cat cat(*catptr);
		
		std::cout << cat.getBrain()->getIdeas()[56] << std::endl;
		std::cout << catptr->getBrain() << " | " <<  catptr->getBrain()->getIdeas()[55] << std::endl;
		std::cout << cat.getBrain() << " | " <<  cat.getBrain()->getIdeas()[55] << std::endl;
	}
	std::cout << catptr->getBrain()->getIdeas()[56] << std::endl;
	delete catptr;
	return 0;
}