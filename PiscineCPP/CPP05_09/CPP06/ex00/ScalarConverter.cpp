/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:08:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 11:50:14 by yassine          ###   ########.fr       */
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
{}


void ScalarConverter::convert(std::string literal) {
	
    try {
        if (literal == "nan" || literal == "inf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
            return;
        }

        for (size_t i = 0; i < literal.size(); i++) {
            if (!isprint(literal[i])) {
                std::cout << "char: Non displayable" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                return;
            }
        }

        int string_to_int = std::stoi(literal);
        int integer = static_cast<int>(string_to_int);
		if (isprint(integer))
		{
			std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << integer << std::endl;
        float string_to_float = std::stof(literal);
        float flottant = static_cast<float>(string_to_float);
        std::cout << "float: " << std::fixed << std::setprecision(1) << flottant << "f" << std::endl;

        double string_to_double = std::stod(literal);
        double _double = static_cast<double>(string_to_double);
        std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;

    } catch (const std::invalid_argument &ex) {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    } catch (const std::out_of_range &ex) {
        std::cout << "out of range.";
    }
}