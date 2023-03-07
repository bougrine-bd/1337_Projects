/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:42:06 by abougrin          #+#    #+#             */
/*   Updated: 2022/02/05 13:48:36 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _arr;
		unsigned int _N;
		unsigned int _t;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const &obj);
		Span &operator = (Span const &obj);
		~Span();
		
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};

#endif