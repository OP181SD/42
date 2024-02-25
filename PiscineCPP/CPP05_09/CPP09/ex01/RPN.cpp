/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:31:35 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 13:58:09 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

RPN::~RPN()
{
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("Error: division by zero");
}

const char *RPN::InvalidExpressionException::what() const throw()
{
	return ("Error: invalid character");
}

const char *RPN::ErrorLen::what() const throw()
{
	return ("Error on your list !");
}

int RPN::_RPN(std::string str)
{
	int	num;
	int	rhs;
	int	lhs;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = std::atoi(&str[i]);
			_stack.push(num);
		}
		else if (str[i] == ADDITION || str[i] == SUBTRACTION
				|| str[i] == MULTIPLICATION || str[i] == DIVISION)
		{
			if (_stack.size() < 2)
				throw RPN::ErrorLen();
			rhs = _stack.top();
			_stack.pop();
			lhs = _stack.top();
			_stack.pop();
			if (str[i] == ADDITION)
				_stack.push(lhs + rhs);
			else if (str[i] == SUBTRACTION)
				_stack.push(lhs - rhs);
			else if (str[i] == MULTIPLICATION)
				_stack.push(lhs * rhs);
			else if (str[i] == DIVISION)
			{
				if (rhs == 0)
					throw RPN::DivisionByZeroException();
				_stack.push(lhs / rhs);
			}
		}
		else if (str[i] != ' ')
		{
			throw RPN::InvalidExpressionException();
		}
	}
	if (_stack.size() == 1)
		return (_stack.top());
	throw RPN::ErrorLen();
}
