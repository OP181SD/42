/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:06:32 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/13 15:41:43 by yasaidi          ###   ########.fr       */
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

bool	isValidFormat(const std::string &line, const std::string &value)
{
	for (size_t i = 1; i < value.size(); ++i)
	{
		if (!isdigit(value[i]) && value[i - 1] != '.' && value[i] != '-')
		{
			std::cout << BAD_INPUT << line << std::endl;
			return (false);
		}
	}
	if (count(line, '|') != 1 || count(line, ' ') != 2 || count(line, '-') > 3
		|| count(line, '.') > 1)
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	return (true);
}

bool	FormatValue(const std::string &line)
{
	size_t	find_pipe;
	int		value_to_int;
	float	value_to_float;

	std::string value;
	find_pipe = line.find("|");
	if (find_pipe != std::string::npos)
		value = line.substr(find_pipe + 1);
	if (!isValidFormat(line, value))
		return (false);
	if (value.size() > 10)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	value_to_int = std::atoi(value.c_str());
	if (value_to_int < 0)
	{
		std::cout << "Error : not a positive numbers \n";
		return (false);
	}
	value_to_float = std::atof(value.c_str());
	if (value_to_float > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	FormatYMD(const std::string &line)
{
	int	year;
	int	months;
	int	days;

	std::stringstream ss(line);
	std::string year_str;
	std::string months_str;
	std::string days_str;
	if (std::getline(ss, year_str, '-') && std::getline(ss, months_str, '-')
		&& std::getline(ss, days_str))
	{
		if (year_str.size() != 4 && months_str.size() == 2
			&& days_str.size() != 2)
		{
			std::cout << BAD_INPUT << line << std::endl;
			return (false);
		}
		std::stringstream(year_str) >> year;
		std::stringstream(months_str) >> months;
		std::stringstream(days_str) >> days;
		if (!IsValidDate(year, months, days))
		{
			std::cout << BAD_INPUT << line << std::endl;
			return (false);
		}
	}
	if (!FormatValue(line))
		return (false);
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
			if (!FormatYMD(line))
			{
				return ;
			}
			else
				std::cout << line;
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
