/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:38:16 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/23 12:46:19 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"

class ShrubberyCreationForm
{
  private:
	std::string _shruberry;

  public:
	// Canonic Form;
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();
	// Create file
	void Createfile(std::string filename);
	// Readfile
	std::string OwnTree(const ShrubberyCreationForm &target);
};
