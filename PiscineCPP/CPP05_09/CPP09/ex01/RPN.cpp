/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:31:35 by yassine           #+#    #+#             */
/*   Updated: 2024/02/05 12:01:49 by yasaidi          ###   ########.fr       */
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
			{
				std::cout << "Error: not enough numbers in the stack" << std::endl;
				exit(1);
			}
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
				{
					std::cout << "Error: division by zero" << std::endl;
					exit(1);
				}
				_stack.push(lhs / rhs);
			}
		}
		else if (str[i] != ' ')
		{
			std::cout << "Error: " << std::endl;
			exit(1);
		}
	}
	if (_stack.size() == 1)
		return (_stack.top());
	std::cout << "Error on your list !" << std::endl;
	exit(1);
}
