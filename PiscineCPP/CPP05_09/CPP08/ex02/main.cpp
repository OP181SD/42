/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:31:15 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/29 08:58:25 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	MutantStack<int> ms;
	for (int i = 1; i <= 5; ++i)
	{
		ms.push(i);
	}
	std::cout << "MutantStack: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// Utilisation de std::list
	std::list<int> l;
	for (int i = 1; i <= 5; ++i)
	{
		l.push_back(i);
	}
	std::cout << "std::list: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}
