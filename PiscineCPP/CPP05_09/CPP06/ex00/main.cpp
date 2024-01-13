/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:43:59 by yassine           #+#    #+#             */
/*   Updated: 2024/01/12 17:55:28 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"



int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return 0;
	}
	ScalarConverter converter;
	if (argc > 2)
	{
		std::cout << "Error: Too many arguments" << std::endl;
		return 0;
	}
	else
		converter.convert(argv[1]);
	return 0;
}
