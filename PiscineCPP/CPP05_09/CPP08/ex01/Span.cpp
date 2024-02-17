/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:25:50 by yassine           #+#    #+#             */
/*   Updated: 2024/02/17 18:16:56 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span & other) : _n(other._n)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		_n = other._n;
	return *this;
}

Span::~Span()
{
}


void Span::addNumber(unsigned int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw Span::SpanException();		
}

void Span::shortestSpan()
{
   if (_v.size() < 2)
		throw Span::NoEnoughValue();
    SpanPrint();
    std::sort(_v.begin(), _v.end());
    SpanPrintSort();

    std::vector<int> diff(_v.size());
    std::adjacent_difference(_v.begin(), _v.end(), diff.begin());
    for (size_t i = 0; i < _v.size(); i++)
    {
        std::cout << "[" << diff[i] << "]";
    }
	
	int min = *std::min_element(diff.begin(), diff.end());
	
	std::cout << "\n";
	std::cout << _GOLD << "Shortest Span: " << min << _END << std::endl;
}

void Span::longestSpan()
{
	if (_v.size() < 2)
		throw Span::NoEnoughValue();
	SpanPrint();
	std::sort(_v.begin(), _v.end());
	SpanPrintSort();	
	int max = _v.back() - _v.front();
	std::cout << _GOLD << "Longest Span: " << max << _END << std::endl;
}


