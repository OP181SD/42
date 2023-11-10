/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:55:33 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:48:52 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Constructeur par défaut de Animal." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructeur de Animal." << std::endl;
}

Animal::Animal(std::string animalType) : type(animalType)
{
	std::cout << "Constructeur avec le type de l'Animal." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Constructeur de copie de Animal" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
        type = rhs.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Meoow\n";
}

std::string Animal::getType() const
{
	return (type);
}
