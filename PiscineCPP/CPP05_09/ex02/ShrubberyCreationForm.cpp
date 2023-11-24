/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:38:08 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/24 11:06:09 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: _shruberry("")
{
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
}
