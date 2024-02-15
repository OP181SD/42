/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:06:32 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/15 12:57:11 by yasaidi          ###   ########.fr       */
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
		return (false);
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
	if (value == " ")
	{
		std::cout << "Error: Invalid value" << std::endl;
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
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	return (true);
}

bool	IsNumeric(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool	FormatYMD(std::string &line)
{
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ')
	{
		std::cout << "Error: Invalid date format" << std::endl;
		return (false);
	}
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);
	if (!IsNumeric(year) || !IsNumeric(month) || !IsNumeric(day))
	{
		std::cout << "Error: Invalid date" << std::endl;
		return (false);
	}
	if (!IsValidDate(std::atoi(year.c_str()), std::atoi(month.c_str()),
			std::atoi(day.c_str())))
	{
		std::cout << "Error: Invalid date" << std::endl;
		return (false);
	}
	if (!FormatValue(line))
		return (false);
	return (true);
}

void	readCSV(std::map<std::string, double> *bitcoinPrices,
				const std::string &filename)
{
	double	price;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string dateStr, priceStr;
		if (std::getline(iss, dateStr, ',') && std::getline(iss, priceStr))
		{
			std::istringstream priceStream(priceStr);
			priceStream >> price;
			(*bitcoinPrices)[dateStr] = price;
		}
	}
	file.close();
}

std::string findNearestDate(const std::map<std::string, double> &bitcoinPrices,
							const std::string &date)
{
	std::map<std::string, double>::const_iterator it = bitcoinPrices.begin();
	std::string nearestDate = "";
	// Parcourir la map
	while (it != bitcoinPrices.end())
	{
		if (it->first <= date)
			nearestDate = it->first;
		else
		{
		
			break ;
		}
		++it;
	}
	return (nearestDate);
}
void	Readfile(std::ifstream &inputfile)
{
	float	bitcoinNb;
	double	bitcoinPrice;

	std::string line;
	std::map<std::string, double> bitcoinPrices;
	std::string filename = "data.csv";
	readCSV(&bitcoinPrices, filename);
	if (std::getline(inputfile, line))
	{
		FormatFirstLine(line);
		while (std::getline(inputfile, line))
		{
			if (!FormatYMD(line))
				continue ;
			else
			{
				std::string date = line.substr(0, 10);
				std::string value = line.substr(13);
				bitcoinNb = std::atof(value.c_str());
				std::string nearestDate = findNearestDate(bitcoinPrices, date);
				if (!nearestDate.empty())
				{
					bitcoinPrice = bitcoinPrices[nearestDate];
					std::cout << date << " => " << value << " "
								<< "= " << bitcoinNb
									* bitcoinPrice << std::endl;
				}
				else
					std::cout << "No nearest date found for " << date << std::endl;
			}
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
