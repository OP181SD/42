/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:08:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 17:11:03 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _literal("") 
{
}

ScalarConverter::ScalarConverter(std::string literal) : _literal(literal)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
		this->_literal = src._literal;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string literal)
{
		
}
