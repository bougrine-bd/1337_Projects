/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:28:18 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/07 13:36:34 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
	try
	{
		std::vector<int> a;

		a.push_back(154);
		a.push_back(13);
		a.push_back(7);
		a.push_back(20);

		easyfind(a, 0);
		std::cout << "EZ Find\n";
	}
	catch(int e)
	{
		std::cout << e << ", Not Found at this Container.\n";
	}
}