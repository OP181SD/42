/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:21 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/25 15:43:14 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>


bool	has_duplicate(std::string s1, int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		for (int j = i + 1; j < argc; ++j)
		{
			if (s1 == argv[j])
			{
				return (true);
			}
		}
	}
	return (false);
}


int	Input(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return (1);
	}
	if (argc == 2)
	{
		std::cout << "Error: Not enough elements" << std::endl;
		return (1);
	}
	if (argc < 2)
	{
		std
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j] != '\0'; ++j)
		{
			if (!std::isdigit(argv[i][j]) && argv[i][j] != '-')
			{
				std::cout << "Error: Not a number" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

template <typename Container>
void	printContainer(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
}

int PmergeMe::Conversion(int argc, char *argv[])
{
	long	string_to_long;

	std::string s1;
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		string_to_long = std::atol(s1.c_str());
		if (string_to_long > std::numeric_limits<int>::max()
			|| string_to_long < std::numeric_limits<int>::min())
		{
			std::cout << "Error: Out of range" << std::endl;
			return (1);
		}
		_vector.push_back(string_to_long);
		_vector[i - 1] = _vector.back();
	}
	if (string_to_long < 0)
	{
		std::cout << "Error:" << std::endl;
		return (1);
	}

	return (0);
}

std::vector<int> PmergeMe::getVector()
{
	return (_vector);
}

int	main(int argc, char *argv[])
{
	PmergeMe p;
	
	if (Input(argc, argv))
		return (1);
	if (p.Conversion(argc, argv))
		return (1);
	std::vector<int> vec = p.getVector();
	clock_t start_vector = clock();
	p.MergeInsertionSort();
	clock_t end_vector = clock();
	double elapsed_time_vector = static_cast<double>(end_vector - start_vector)
		/ CLOCKS_PER_SEC * 1000000;
	std::cout << "Before: ";
	printContainer(vec);
	std::cout << std::endl;
	std::cout << "After: ";
	printContainer(p.getVector());
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << elapsed_time_vector << " us" << std::endl;
	std::deque<int> dq(vec.begin(), vec.end());
	clock_t start_deque = clock();
	p.MergeInsertionSort();
	clock_t end_deque = clock();
	double elapsed_time_deque = static_cast<double>(end_deque - start_deque)
		/ CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << dq.size() << " elements with std::deque: " << elapsed_time_deque << " us" << std::endl;
	return (0);
}