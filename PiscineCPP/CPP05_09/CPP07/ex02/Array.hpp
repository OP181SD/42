/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:39:06 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/23 16:54:59 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stddef.h>

template <typename T>

class Array
{
  public:
	Array(void);
	Array(unsigned int n);
	Array(Array const &src);
	~Array(void);
	Array &operator=(Array const &rhs);
	T &operator[](unsigned int i) const;
	unsigned int size(void) const;
  private:
	T *_array;
	unsigned int _size;
	class OutOfLimitsException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Out Of Limits Exception");
		}
	};
};

#include "Array.tpp"