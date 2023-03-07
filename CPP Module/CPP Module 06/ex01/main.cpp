/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:25:57 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/24 15:12:56 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data data;
    Data *d;
    uintptr_t c = 0;

    c = serialize(&data);
    d = deserialize(c);
    std::cout   << "char: " << d->getChar() << "\n" 
                << "int: " << d->getInt() << "\n"
                << "float: " << d->getFloat() << "\n";
    return 0;
}