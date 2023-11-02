/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:21:39 by yassine           #+#    #+#             */
/*   Updated: 2023/11/02 13:24:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	Sed_is_for_loser(std::string &filename, std::string &s1,
		std::string &s2)
{
	size_t	found_s1;

	std::ifstream file(filename.c_str());
	if (file.is_open())
	{
		std::string content;
		std::string line;
		while (std::getline(file, line))
		{
			found_s1 = line.find(s1);
			while (found_s1 != std::string::npos)
			{
				line.erase(found_s1, s1.length());
				line.insert(found_s1, s2);
				found_s1 = line.find(s1, found_s1 + s2.length());
			}
			content += line + "\n";
		}
		file.close();
		filename.append(".replace");
		std::ofstream output_file(filename.c_str());
		if (output_file.is_open())
		{
			output_file << content;
			output_file.close();
		}
		else
			std::cerr << "Error: Cannot open the output file" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: The program requires exactly 3 arguments." << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (s1.empty() || s2.empty())
	{
		std::cerr << "S1 or S2 are empty" << std::endl;
		return (1);
	}
	if (!std::ifstream(filename.c_str()))
	{
		std::cerr << "Error: The input file does not exist." << std::endl;
		return (1);
	}
	Sed_is_for_loser(filename, s1, s2);
	return (0);
}
