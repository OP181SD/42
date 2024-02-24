/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:25:10 by yassine           #+#    #+#             */
/*   Updated: 2024/02/21 10:14:28 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <numeric>
#include "colors.hpp"
#include <limits>

class Span
{
private:
    unsigned int _n;
	std::vector<unsigned int> _v;
public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(unsigned int n);
	void SpanPrint();
	void SpanPrintSort();
	void shortestSpan();
	void longestSpan();
    class SpanException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
	
	class NoEnoughValue  : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};