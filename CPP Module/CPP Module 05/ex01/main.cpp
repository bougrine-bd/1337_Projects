/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:05:13 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 09:14:16 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream &operator << (std::ostream &output, const Form &obj);

int main()
{
	try
	{
		Bureaucrat b("abdeljalil", 11);
		Form f("main form", 20 , 50);

		std::cout << b << std::endl;
		b.decrement();
		std::cout << b << std::endl;
		b.increment();
		std::cout << b << std::endl;
		std::cout << std::endl;
		b.signForm(f);
		std::cout << std::endl;
		std::cout <<  f << std::endl;
		std::cout <<  b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}