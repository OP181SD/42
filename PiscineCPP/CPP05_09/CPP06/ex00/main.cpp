/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:01:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 21:39:28 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Please use ./convert (argv[0])";
		return (1);
	}
	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Char invalide." << '\n';
		}
	}
	return 0;
}
