/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:25:52 by abougrin          #+#    #+#             */
/*   Updated: 2022/02/05 13:31:31 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	if (mstack.empty())
		std::cout << "stack empty\n";
	else
		std::cout << "stack not empty\n";

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "top-stack: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "stack size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(88);
	mstack.push(737);
	mstack.push(9);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	std::cout << "iterator point at: " << *it << std::endl;
	--it;
	std::cout << "iterator point at: " << *it << std::endl;
	std::advance(it, 2);
	std::cout << "iterator point at: " << *it << std::endl;
	std::advance(it, -2);
	std::cout << "iterator point at: " << *it << std::endl;
	


	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}	
	std::cout << "top-stack: " << mstack.top() << std::endl;
	std::cout << "stack size: " << mstack.size() << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
