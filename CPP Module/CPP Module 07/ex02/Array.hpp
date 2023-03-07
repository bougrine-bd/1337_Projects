/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:54:26 by abougrin          #+#    #+#             */
/*   Updated: 2022/01/05 12:21:50 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &obj);
		Array &operator = (Array const &obj);
		T	&operator [] (unsigned int index);
		T const &operator [] (unsigned int index) const;
		~Array();
		
		unsigned int  size() const;
};

template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template<typename T>
Array<T>::Array(Array<T> const &obj) : _array(NULL), _size(obj._size)
{
	*this = obj;
}

template<typename T>
Array<T>  &Array<T>::operator = (Array<T> const &obj)
{
	delete [] _array;
	if (obj._array)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = obj._array[i];
	}
	else
		_array = NULL;
	return (*this);
}

template<typename T>
T	&Array<T>::operator [] (unsigned int index)
{
	if (index < 0 || index >= _size)
		throw std::exception();
	return (_array[index]);
}

template<typename T>
T	const &Array<T>::operator [] (unsigned int index) const
{
	if (index < 0 || index >= _size)
		throw std::exception();
	return (_array[index]);
}

template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template<typename T>
unsigned int  Array<T>::size() const
{
	return (_size);
}

#endif