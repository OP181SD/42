/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:54:47 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/18 20:23:17 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <stdlib.h>
#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
  public:
	static void convert(const std::string &literal);
};
