/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:38:08 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/23 12:43:20 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: _shruberry("")
{
	std::cout << "Constructeur par defaut du Shrubberry \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: _shruberry(other._shruberry)
{
	*this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
	: _shruberry(target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		_shruberry = rhs._shruberry;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructeur de Shurberry\n";
}

void ShrubberyCreationForm::Createfile(std::string filename)
{
	std::cout << "Veuillez saisir le nom du fichier que vous souhaitez créer :\n";
	std::cin >> filename;
	std::ifstream ifile(filename.c_str());
	if (ifile)
	{
		std::cerr << BOLD << RED << "Le fichier \"" << filename << "\" existe déjà." << RESET << std::endl;
		return ;
	}
	std::ofstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << BOLD << RED << "Erreur lors de la création du fichier " << filename << RESET << std::endl;
		return ;
	}
	file.close();
	std::cout << BOLD << GREEN << "Fichier \"" << filename << "\" créé avec succès." << RESET << std::endl;
}

std::string ShrubberyCreationForm::OwnTree(const ShrubberyCreationForm &target)
{
	std::ifstream Tree(target._shruberry.c_str());
	std::string content;
	if (Tree.is_open())
	{
		std::string line;
		while (std::getline(Tree, line))
		{
			std::cout << line << std::endl;
			content += line;
			content += '\n';
		}
		Tree.close();
	}
	else
		return ("Erreur lors de la création du fichier\n");
	return (content);
}
