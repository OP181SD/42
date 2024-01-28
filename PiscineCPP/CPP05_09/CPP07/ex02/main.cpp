/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:21 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/25 12:27:46 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 10

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " [display|exceptions]" << std::endl;
		return (1);
	}

	std::string mode(argv[1]);

	if (mode != "display" && mode != "exceptions")
	{
		std::cerr << "Mode non reconnu. Utilisez 'display' ou 'exceptions'." << std::endl;
		return (1);
	}
	if (mode == "display")
	{
		Array<int> numbers(MAX_VAL);
		int *ptr = new int[MAX_VAL];

		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = i;
			numbers[i] = value;
			ptr[i] = value;
		}

		if (numbers.size() == 0)
		{
			std::cout << "Le tableau  est vide." << std::endl;
			return (1);
		}
		else
		{
			std::cout << "Tableau numbers : ";
			for (int i = 0; i < MAX_VAL; i++)
			{
				std::cout << numbers[i] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "Tableau ptr : ";
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << ptr[i] << " ";
		}
		std::cout << std::endl;

		delete[] ptr;
	}
	else if (mode == "exceptions")
	{
		Array<int> numbers(MAX_VAL);

		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception lors de l'accès à un index négatif : " << e.what() << '\n';
		}

		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception lors de l'accès à un index hors limite : " << e.what() << '\n';
		}
	}
	return (0);
}