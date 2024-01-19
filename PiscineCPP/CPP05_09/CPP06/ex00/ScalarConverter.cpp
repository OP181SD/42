/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:54:36 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/18 20:23:03 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)(rhs);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool	FormatInput(std::string literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((std::isdigit(literal[0]) || literal.length() > 1))
		{
			if (!std::isdigit(literal[i]) && literal[i] != '.'
				&& literal[i] != '-' && literal[i] != 'f')
			{
				std::cout << "impossible.\n";
				return (false);
			}
		}
	}
	return (true);
}

int	FormatMinusPlus(std::string literal)
{
	for (size_t i = 1; i < literal.size(); i++)
	{
		if (literal[i] == '-' || literal[i] == '+')
		{
			std::cout << "impossible.\n";
			return (false);
		}
	}
	return (true);
}

int	Int_Overflow(long a)
{
	return (a > INT_MAX || a < INT_MIN || a > CHAR_MAX || a < CHAR_MIN);
}

int	Float_Overflow(float a)
{
	return (a > static_cast<float>(INT_MAX) || a < static_cast<float> (INT_MIN));
}

int	Double_Overflow(double a)
{
	return (a > static_cast<double>(INT_MAX) || a < static_cast<double>(INT_MIN));
}

bool	InputEachCase(const std::string literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "inf"
		|| literal == "inff" || literal == "-inff" || literal == "+inf"
		|| literal == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return (false);
	}
	else if (literal.empty())
	{
		std::cout << "impossible.\n";
		return (false);
	}
	return (true);
}

void	FormatChar(char isChar, long string_to_int)
{
	if (std::isprint(isChar) && !std::isdigit(isChar))
		std::cout << "char: '" << isChar << "'" << std::endl;
	else if (!std::isprint(isChar))
		std::cout << "char: Non displayable" << std::endl;
	else if (Int_Overflow(string_to_int))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(string_to_int))
		std::cout << "char: "
					<< "'" << static_cast<char>(string_to_int) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	char isChar;
	
	long string_to_int;
	float string_to_float;
	double string_to_double;

	isChar = literal.c_str()[0];
	string_to_int = (std::strtol(literal.c_str(), NULL, 10));
	string_to_float = static_cast<float>(std::strtof(literal.c_str(), NULL));
	string_to_double = std::strtod(literal.c_str(), NULL);

	if (InputEachCase(literal) == false)
		return ;

	if (FormatMinusPlus(literal) == false)
		return ;

	if (FormatInput(literal) == false)
		return ;

	FormatChar(isChar, string_to_int);
	if (string_to_int > INT_MAX || string_to_int < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(string_to_int) << std::endl;

	if (Float_Overflow(string_to_float))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << string_to_float << "f" << std::endl;

	if (Double_Overflow(string_to_double))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << string_to_double << std::endl;
}