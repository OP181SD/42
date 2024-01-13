/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:37:13 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 23:28:27 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <exception>

class ScalarConverter
{
public:
	ScalarConverter();
	static void convert(std::string const & literal);
	ScalarConverter(ScalarConverter const & );
	ScalarConverter & operator=(ScalarConverter const &);
	~ScalarConverter();
};


