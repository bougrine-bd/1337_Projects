/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:17:30 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/03 11:20:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base	*generate(void)
{
	srand(time(0));
	int r = rand();
	int i = r % 3;
	if (i == 0)
	{
		A	*a = new A();
		return (a);
	}
	else if (i == 1)
	{
		B	*b = new B();
		return (b);
	}
	C	*c = new C();
	return (c);
}

void identify(Base *p)
{
	A *dA;
	B *dB;
	C *dC;
	if ((dA = dynamic_cast<A *>(p)))
		std::cout << "A\n";
	else
	{
		if ((dB = dynamic_cast<B *>(p)))
			std::cout << "B\n";
		else
			if ((dC = dynamic_cast<C *>(p)))
				std::cout << "C\n";
	}
}

void identify(Base &p)
{
	try
	{
		A &dA = dynamic_cast<A &>(p);
		std::cout << "A\n";
	}
	catch (std::exception &e) 
	{
		try
		{
			B &dB = dynamic_cast<B &>(p);
			std::cout << "B\n";
		}
		catch(std::exception &e)
		{
			try
			{
				C &dC = dynamic_cast<C &>(p);
				std::cout << "C\n";
			}
			catch(std::exception &e)
			{
			}
		}
	}
}

int main()
{
	Base *basePtr = generate();
	Base &baseRef = *basePtr;
	identify(basePtr);
	identify(baseRef);
}