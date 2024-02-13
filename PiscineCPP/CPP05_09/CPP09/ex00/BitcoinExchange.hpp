/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:02:27 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/08 16:16:02 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fcntl.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <limits.h>

// Input
#define INV_ARGS "Error: could not open file.\n"
#define INV_OPN_FILE "Error: when we try to open the file\n"
#define BAD_INPUT "Error: bad input => "


#define YEAR 2009
#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define JUNE 6
#define SEPTEMBER 9
#define NOVEMBER 11
#define DECEMBER 12
#define DAYS 1


struct DateInfo {
    long year;
    long month;
    long day;
};

class BitcoinExchange
{
  private:
  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();
};

int		Input(int argc, char **argv);
void	Readfile(std::ifstream &inputfile);

