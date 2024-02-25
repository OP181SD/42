/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:31:44 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 13:51:07 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
		return (1);
	}
	else if (argv[1][0] == '\0')
	{
		std::cout << "Error: empty string" << std::endl;
		return (1);
	}

	try
	{
		if (argc == 2)
		{
			RPN rpn;
			std::cout << rpn._RPN(argv[1]) << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}