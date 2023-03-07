/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:54:24 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/05 12:44:43 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main()
{
	try
	{
		Array<int>  arr(3);
		Array<std::string> arr1(2);
		arr1[0] = "abdeljalil";
		arr1[1] = "bougrine";
		Array<std::string>  const arr2(arr1);
		
		std::cout << "size of arr: " << arr.size() << std::endl;    
		std::cout << "size of arr2: " << arr2.size() << std::endl;
		
		// arr2[0] = "coco";
		std::cout << "arr2[]: " << arr2[1] << std::endl;
		arr[0] = 19;
		std::cout << arr[0] << std::endl;    
		arr[1] = 98;
		std::cout << arr[1] << std::endl;    
		arr[2] = 53;
		std::cout << arr[2] << std::endl;    
	}
	catch (std::exception &e)
	{
		std::cout << "Out Of Range" << std::endl;
	}
}