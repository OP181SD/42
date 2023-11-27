/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:55:30 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 17:09:33 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>


class ScalarConverter
{
private:
		std::string _literal;
public:
	ScalarConverter();
	ScalarConverter(std::string literal);
	ScalarConverter(ScalarConverter const & src);
	ScalarConverter & operator=(ScalarConverter const & src);
	~ScalarConverter();
	static void convert(std::string literal);
};