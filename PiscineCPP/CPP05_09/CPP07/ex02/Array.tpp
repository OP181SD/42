/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:39:57 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/23 16:54:48 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
	: _array(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &src)
	: _array(new T[src._size]), _size(src._size)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_array = new T[rhs._size];
		_size = rhs._size;
	}
	for (unsigned int i = 0; i < rhs._size; i++)
	{
		_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const 
{
	if (i >= _size)
		throw OutOfLimitsException();
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}