/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:17:10 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/25 12:16:52 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print_int(int const &x)
{
	std::cout << x << " ";
}

void	print_string(std::string const &x)
{
	std::cout << x << " ";
}

void print_char(char const &x)
{
	std::cout << x << " ";
}

int	main(void)
{

	int tab[5] = {1, 2, 3, 4, 5};
	std::cout << "int tab[5] = {1, 2, 3, 4, 5};" << std::endl;
	::iter(tab, 5, print_int);
	std::cout << std::endl;

	std::cout << "Array of strings:" << std::endl;
	std::string str[3] = {"Hello", "World", "!"};
	::iter(str, 3, print_string);
	std::cout << std::endl;

	std::cout << "Array of chars:" << std::endl;
	char c[3] = {'a', 'b', 'c'};
	::iter(c, 3, print_char);
	std::cout << std::endl;

	return (0);
}
