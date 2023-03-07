/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:42:04 by abougrin          #+#    #+#             */
/*   Updated: 2022/02/08 09:17:32 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : _N(n), _t(0)
{
}

Span::Span(Span const &obj)
{
    *this = obj;
}

Span &Span::operator = (Span const &obj)
{
    _arr = obj._arr;
    return(*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (_t >= _N)
        throw "More Than the Size You Allocated";
    _arr.push_back(num);
    _t++;
}

int Span::shortestSpan()
{
    if (_t <= 1)
        throw "There is Less or Equal Than One Element";
    std::vector<int> arr = _arr;
    sort(arr.begin(), arr.end());
    long shortSpan = __LONG_MAX__;
    int arrsize = arr.size();
    for (int i = 0; i < arrsize - 1; i++)
    {
        if ((arr[i + 1] - arr[i]) <= shortSpan)
            shortSpan = arr[i + 1] - arr[i];
    }
    return (shortSpan);
}

int Span::longestSpan()
{
    if (_t <= 1)
        throw "There is Less or Equal Than One Element";
    return (*max_element(_arr.begin(), _arr.end()) - *min_element(_arr.begin(), _arr.end()));
}