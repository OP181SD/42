/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:04:00 by yassine           #+#    #+#             */
/*   Updated: 2024/01/28 12:04:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
	: _n(0)
{
}

Span::Span(unsigned int n)
	: _n(n)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_vec.size() < _n)
		_vec.push_back(n);
	else
		throw std::exception();
}

int Span::shortestSpan()
{
	int	diff;

	if (_vec.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 _vec.");
	std::sort(_vec.begin(), _vec.end());
	diff = std::numeric_limits<int>::max();
	std::vector<int> temp(_vec.size());
	std::adjacent_difference(_vec.begin(), _vec.end(), temp.begin());
	for (int i = 1; i < temp.size(); ++i)
	{
		diff = std::min(diff, temp[i]);
	}
	return (diff);
}

int Span::longestSpan()
{
	int diff;

	if (_vec.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 _vec.");

	std::sort(_vec.begin(), _vec.end());

	diff = std::numeric_limits<int>::min();

	for (int i = 0; i < _vec.size(); ++i)
	{
		diff = std::max(diff, _vec[i]);
	}
	int first_value = *_vec.begin();

	return (diff - first_value);
}