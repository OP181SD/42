/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:08:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 21:36:52 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _literal("") 
{}

ScalarConverter::ScalarConverter(std::string literal) : _literal(literal)
{}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
		_literal = src._literal;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string literal)
{

	int string_to_int = std::stoi(literal);
	float string_to_float = std::stof(literal);
	double string_to_double = std::stod(literal);
	
	std::cout << "char: Non displayable\n";	
	std::cout << "int: " << string_to_int << std::endl;
	std::cout << "float: " << string_to_float << std::endl;
	std::cout << "double: " << string_to_double << std::endl;

}