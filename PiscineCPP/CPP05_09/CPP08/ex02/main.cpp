/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:31:15 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/21 10:31:41 by yasaidi          ###   ########.fr       */
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

	std::cout << "Reverse " << std::endl;

	MutantStack<int> ms2;
	for (int i = 1; i <= 5; ++i)
	{
		ms2.push(i);
	}
	std::cout << "MutantStack: ";
	for (MutantStack<int>::reverse_iterator it = ms2.rbegin(); it != ms2.rend(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	// Utilisation de std::list
	std::list<int> l2;
	for (int i = 1; i <= 5; ++i)
	{
		l2.push_back(i);
	}
	std::cout << "std::list: ";
	for (std::list<int>::reverse_iterator it = l2.rbegin(); it != l2.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}

