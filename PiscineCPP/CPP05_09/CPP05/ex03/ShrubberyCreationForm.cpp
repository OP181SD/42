/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:48:32 by yassine           #+#    #+#             */
/*   Updated: 2024/01/09 10:53:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm ::ShrubberyCreationForm () : AForm("default", 145, 137)
{}

ShrubberyCreationForm ::ShrubberyCreationForm (std::string target) : AForm("ShrubberyCreationForm ", 145, 137), _target(target)
{}


ShrubberyCreationForm ::ShrubberyCreationForm (ShrubberyCreationForm  const & other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm ::~ShrubberyCreationForm ()
{}

ShrubberyCreationForm  & ShrubberyCreationForm ::operator=(ShrubberyCreationForm  const & rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}	

void ShrubberyCreationForm::_executeAction() const
{
	std::fstream file((_target + "_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
	if (!file.is_open())
	{
		std::cout << "Error: file is not open" << std::endl;
		return;
	}
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}
