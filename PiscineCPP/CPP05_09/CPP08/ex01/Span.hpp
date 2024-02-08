/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:02:18 by yassine           #+#    #+#             */
/*   Updated: 2024/01/28 10:35:50 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <vector>

class Span
{
  private:
	unsigned int _n;
	std::vector<int> _vec;

  public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	~Span();
};
