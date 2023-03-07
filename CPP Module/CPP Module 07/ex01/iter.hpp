/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:22:07 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/05 10:12:08 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void print(T array)
{
    std::cout << array << std::endl;
}

template<typename T>
void iter(T *array, int size, void (*print)(T))
{
    for (int i = 0; i < size; i++)
        print(array[i]);
}

#endif