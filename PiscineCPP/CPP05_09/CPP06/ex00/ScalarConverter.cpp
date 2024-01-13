/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:08:20 by yassine           #+#    #+#             */
/*   Updated: 2024/01/13 09:08:43 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &)
{
	return (*this);
}

void Input(std::string const & literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
			return;
	}
}


bool literal_toi_int(std::string const & literal)
{
	long a_toi = std::strtol(literal.c_str(), NULL, 10);
	if (a_toi < INT_MIN || a_toi > INT_MAX || a_toi > CHAR_MAX || a_toi < CHAR_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		return(false);
	}
	return (true);
}

bool literal_to_float(std::string const &literal)
{
   float a_tof = std::strtof(literal.c_str(),NULL);
   if (a_tof > CHAR_MAX || a_tof < CHAR_MIN)
   {
	   std::cout << "float: impossible" << std::endl;
	   return false;
   }
    return true;
}

bool literal_to_double(std::string const &literal)
{
    double a_double = std::strtod(literal.c_str(), NULL);
    if (a_double > CHAR_MAX || a_double < CHAR_MIN)
	{
		std::cout << "double: impossible" << std::endl;
		return false;
	}
    return true;
}

void ScalarConverter::convert(std::string const & literal)
{
	Input(literal);

    long a_toi = std::strtol(literal.c_str(), NULL, 10);
	if (literal_toi_int(literal) == false)
		return ;

    float a_tof = std::strtof(literal.c_str(), NULL);
	if (literal_to_float(literal) == false)
		return ;

    double a_double = std::strtod(literal.c_str(), NULL);
	if (literal_to_double(literal) == false)
		return ;

    if (isprint(a_toi))
        std::cout << "char: " << "'" << static_cast<char>(a_toi) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
	
	
    std::cout << "int: " << a_toi << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a_tof) << "f" << std::endl;	
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a_double) << std::endl;
}