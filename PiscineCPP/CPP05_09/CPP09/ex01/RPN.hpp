/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:34:16 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 13:55:35 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>

#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();
	int _RPN(std::string str);
	class InvalidExpressionException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class DivisionByZeroException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class ErrorLen : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

