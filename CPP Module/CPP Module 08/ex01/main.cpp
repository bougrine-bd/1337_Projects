/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:42:01 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/07 15:21:21 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	try
	{
		{
			Span sp = Span(5);

			sp.addNumber(-1);
			sp.addNumber(3);
			sp.addNumber(-17);
			sp.addNumber(9);

			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		{
			int rang = 10000;
			Span sp = Span(rang);

			srand(time(0));
			for (int i = 0; i < rang; i++)
				sp.addNumber(rand());

			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
	}
	catch(char const *e)
	{
		std::cerr << e << '\n';
	}
	
}