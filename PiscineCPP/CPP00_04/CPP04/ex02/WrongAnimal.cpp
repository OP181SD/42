/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:07:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 15:58:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("Wrong Animal")
{
	std::cout << "Constructeur de WrongAnimal.\n";
}

WrongAnimal::WrongAnimal(std::string WrongAnimal)
	: type(WrongAnimal)
{
	std::cout << "Constructeur de WrongAnimal avec un membre.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Constructeur de copie de WrongAnimal\n";
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructeur de WrongAnimal.\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "Le son de WrongAnimal.\n";
}

std::string WrongAnimal::getType() const
{
	return (type);
}
