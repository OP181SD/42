/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:06:32 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/13 10:57:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isBissextile(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return (true);
	else
		return (false);
}

bool	IsValidDate(int year, int month, int day)
{
	if (year < YEAR || month < JANUARY || month > DECEMBER || day < DAYS)
		return (false);
	if (month == FEBRUARY)
	{
		if (day > 28 && !isBissextile(year))
			return (false);
		if (day > 29 && isBissextile(year))
			return (false);
	}
	if (month == MARCH && day > 31)
		return (false);
	if ((month == APRIL || month == JUNE || month == SEPTEMBER
			|| month == NOVEMBER) && day > 30)
		return (false);
	return (true);
}

void	FormatFirstLine(const std::string &line)
{
	if (line == "date | value")
		std::cout << line << std::endl;
	else
		std::cout << "Error: Invalid first line" << std::endl;
}

size_t	count(const std::string &str, char target)
{
	size_t	occurrences;

	occurrences = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == target)
			++occurrences;
	}
	return (occurrences);
}

bool	isValidFormat(const std::string &line)
{
	if (count(line, '|') != 1 || count(line, ' ') != 2 || count(line, '-') > 3
		|| count(line, '.') > 1)
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	return (true);
}

void	Readfile(std::ifstream &inputfile)
{
	std::string line;
	if (std::getline(inputfile, line))
	{
		FormatFirstLine(line);
		while (std::getline(inputfile, line))
		{
			
		}
	}
}

int	Input(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << INV_ARGS;
		return (1);
	}
	std::string file;
	file = argv[1];
	std::ifstream inputfile(file.c_str());
	if (!inputfile.is_open())
	{
		std::cerr << INV_OPN_FILE;
		return (1);
	}
	Readfile(inputfile);
	return (0);
}

int	main(int argc, char **argv)
{
	if (Input(argc, argv))
		return (1);
	return (0);
}
