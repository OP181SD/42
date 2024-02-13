/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:21 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/11 19:51:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	only_digits(std::string s1)
{
	for (size_t j = 0; j < s1.size(); ++j)
	{
		if (!std::isdigit(s1[j]))
		{
			std::cerr << "Error: Invalid input char detected " << std::endl;
			return (1);
		}
	}
	return (0);
}

int	is_duplicate(std::string s1, int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		for (int j = i + 1; j < argc; ++j)
		{
			if (s1 == argv[j])
			{
				std::cerr << "Error: Duplicate input" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int	out_of_range(std::string s1)
{
	long	string_to_long;

	string_to_long = std::atol(s1.c_str());
	if (string_to_long > std::numeric_limits<int>::max()
		|| string_to_long < std::numeric_limits<int>::min())
	{
		std::cerr << "Error: Out of range" << std::endl;
		return (1);
	}
	return (0);
}

int	Parsing(std::string s1, int argc, char *argv[])
{
	if (only_digits(s1) || is_duplicate(s1, argc, argv) || out_of_range(s1))
		return (1);
	return (0);
}

int	Input(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string s1 = argv[i];
		if (Parsing(s1, argc, argv))
			return (1);
	}
	return (0);
}

void	DisplayVector(const std::vector<int> &vector)
{
	std::cout << "Original Vector : \n";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << "[" << vector[i] << "]";
	}
	std::cout << std::endl;
}

void	SortedDisplayVector(const std::vector<int> &vector)
{
	std::cout << "Sorted Vector : \n";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << "[" << vector[i] << "]";
}

int	ElementPaired(const std::vector<int> &vector, size_t index)
{
	return (index + 1 < vector.size());
}



std::vector <int>	FordJhonson(std::vector<int> &vector)
{
	size_t	n;

	if (vector.size() <= 1)
		return ;
	std::cout << "Divide Each pair : \n";
	n = vector.size();
	for (size_t i = 0; i < n; i += 2)
	{
		std::cout << "[" << vector[i] << "]";
		if (ElementPaired(vector, i + 1))
			std::cout << "[" << vector[i + 1] << "]";
		std::cout << " |";
	}
	std::cout << "\n";
	std::cout << "Determinate Maximum of each pair : \n";
	for (size_t i = 0; i < vector.size(); i += 2)
	{
		if (i + 1 < vector.size() && vector[i] < vector[i + 1])
		{
			std::swap(vector[i], vector[i + 1]);
		}
		std::cout << "[" << vector[i] << "]";
	}
	std::vector <int> maximas;
}

void	Conversion(int argc, char *argv[], std::vector<int> &vector)
{
	long	string_to_long;

	std::string s1;
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		string_to_long = std::atol(s1.c_str());
		vector.push_back(string_to_long);
		vector[i - 1] = vector.back();
		// std::cout << vector[i - 1] << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	if (Input(argc, argv))
		return (1);
	std::vector<int> vector;
	Conversion(argc, argv, vector);
	FordJhonson(vector);
	return (0);
}