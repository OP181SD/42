/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:58:01 by yassine           #+#    #+#             */
/*   Updated: 2023/11/23 12:49:04 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int	InterfaceCreationFile(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << BOLD << "Bienvenue sur l'entrée standard :" << RESET << std::endl;
		std::cout << "Veuillez fournir un nom de fichier en argument pour poursuivre la création du fichier." << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		std::string args = argv[1];
		if (args.empty())
		{
			std::cout << BOLD << RED << "Erreur : vous avez saisi un argument vide." << RESET << std::endl;
			return (1);
		}
		if (args != "Creation")
		{
			std::cout << BOLD << GREEN << "Bienvenue sur l'espace de création du fichier." << RESET << std::endl;
			std::cout << BOLD << RED << "Veuillez saisir : 'Creation' pour créer le fichier." << RESET << std::endl;
			return (1);
		}
		else if (args == "OK")
		{
			printf("ok");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int input = InterfaceCreationFile(argc, argv);
	if (input)
		return (1);
	std::string args = argv[1];
	ShrubberyCreationForm call(args);
	call.Createfile(args);
	call.OwnTree(args);
	return (0);
}