/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/01/03 21:36:46 by yassine           #+#    #+#             */
/*   Updated: 2024/01/12 20:08:07 by yassine          ###   ########.fr       */
=======
/*   Created: 2023/11/27 17:08:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/29 10:12:24 by yassine          ###   ########.fr       */
>>>>>>> 8094b989d92e19c2282450973ddb8f0438e3d2b4
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
	
<<<<<<< HEAD
	
    std::cout << "int: " << a_toi << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a_tof) << "f" << std::endl;	
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a_double) << std::endl;
=======
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
        int string_to_int = atoi(literal.c_str());
        int integer = static_cast<int>(string_to_int);
		if (isprint(integer))
			std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << integer << std::endl;
        float string_to_float = atof(literal.c_str());
        float flottant = static_cast<float>(string_to_float);
        std::cout << "float: " << std::fixed << std::setprecision(1) << flottant << "f" << std::endl;

         double string_to_double = strtod(literal.c_str(), NULL);
        double _double = static_cast<double>(string_to_double);
        std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;

    } catch (const std::invalid_argument &ex) {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    } catch (const std::out_of_range &ex) {
        std::cout << "out of range.";
    }
>>>>>>> 8094b989d92e19c2282450973ddb8f0438e3d2b4
}