/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:06:32 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/14 11:43:23 by yassine          ###   ########.fr       */
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

	if (year < YEAR || month < JANUARY || month > DECEMBER || day < DAYS
		|| day > 31 || year > 2022)
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

bool	isFloat(const std::string &str)
{
	int	isDot;
	int	i;

	if (str.empty() || str[0] == '.' || str[str.size() - 1] == '.') 
        return false;

	isDot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			isDot++;
		if (isDot > 1)
			return (false);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
		i++;
	}
	return (true);
}

bool	isValidFormat(const std::string &line, const std::string &value)
{
	
	if (isFloat(value))
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
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
	else if (value_to_float < 0)
		return (false);
	return (true);
}

bool FormatYMD(const std::string& line) 
{
    char dateComponents[3][10];

    std::stringstream ss(line);

    for (int i = 0; i < 3; ++i) 
	{
        ss.getline(dateComponents[i], 10, '-');
        if (ss.fail() && i < 2) { 
            std::cout << BAD_INPUT << line << std::endl;
            return false;
        }
    }
	
    int year = std::atoi(dateComponents[0]);
    int month = std::atoi(dateComponents[1]);
    int day = std::atoi(dateComponents[2]);
	
    if (!IsValidDate(year, month, day)) {
        std::cout << BAD_INPUT << line << std::endl;
        return false;
    }
    if (!FormatValue(line)) {
        return false;
    }
    return true;
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
				return ;
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
