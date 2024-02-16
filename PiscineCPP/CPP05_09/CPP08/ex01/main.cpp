/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:05:25 by yassine           #+#    #+#             */
/*   Updated: 2024/02/16 13:11:26 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

void	runEasyMode(void)
{
	Span	sp;

	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	runDemstify(void)
{
	int		diff;
	
	std::vector<int> _vec;
	_vec.size();
	
	_vec.push_back(8);
	_vec.push_back(3);
	_vec.push_back(17);
	_vec.push_back(9);
	if (_vec.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 _vec.");
		
	std::cout << "Original vector: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
	std::sort(_vec.begin(), _vec.end());
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
	diff = std::numeric_limits<int>::max();
	std::vector<int> temp(_vec.size());
	std::adjacent_difference(_vec.begin(), _vec.end(), temp.begin());
	std::cout << "Differences: ";
	for (size_t i = 1; i < temp.size(); ++i)
	{
		std::cout << "[" << temp[i] << "]";
		diff = std::min(diff, temp[i]);
	}
	std::cout << std::endl;
	std::cout << diff << std::endl;
}

void	runHardMode(void)
{
	Span	sp;

	sp = Span(10000);
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i)
	{
		sp.addNumber(rand() % 10000);
	}
	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Span	s;

	if (argc == 1)
	{
		std::cerr << "Usage: " << argv[0] << " [Easy|Hard|Demystify]" << std::endl;
		return (1);
	}
	std::string mode = argv[1];
	if (mode != "Easy" && mode != "Hard" && mode != "Demystify")
	{
		std::cout << "Please enter a valid mode" << std::endl;
		return (1);
	}
	if (mode == "Easy")
	{
		runEasyMode();
	}
	else if (mode == "Hard")
	{
		runHardMode();
	}
	else if (mode == "Demystify")
	{
		runDemstify();
	}
	return (0);
}
