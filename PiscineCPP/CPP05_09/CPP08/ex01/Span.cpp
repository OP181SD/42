/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:04:00 by yassine           #+#    #+#             */
/*   Updated: 2024/02/16 13:11:50 by yassine          ###   ########.fr       */
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
	for (size_t i = 1; i < temp.size(); ++i)
	{
		diff = std::min(diff, temp[i]);
	}
	return (diff);
}

int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::logic_error("Cannot find span with less than 2 elements.");
    std::sort(_vec.begin(), _vec.end());

    int max_value = _vec.back();
    int min_value = _vec.front(); 
	
    return (max_value - min_value); 
}