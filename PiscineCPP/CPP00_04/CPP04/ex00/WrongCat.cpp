/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:31 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 14:10:45 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Constructeur de WrongCat.\n";
}

WrongCat::WrongCat(std::string wrongCat)
	: type(wrongCat)
{
	std::cout << "Constructeur de WrongCat avec un membre.\n";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "Constructeur de copie de WrongCat\n";
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructeur de WrongCat.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Le son de WrongCat.\n";
}

std::string WrongCat::getType() const
{
	return (type);
}