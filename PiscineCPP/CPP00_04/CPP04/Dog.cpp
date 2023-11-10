/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:50 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:49:34 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Constructeur par défaut de Dog." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructeur de Dog." << std::endl;
}

Dog::Dog(std::string animalType) : Animal(animalType)
{
	std::cout << "Constructeur Dog qui hérite de la class Animal" << std::endl;
}

Dog::Dog(const Animal &other) : Animal(other) 
{
	std::cout << "Constructeur de copie de Dog.\n";
}

Dog& Dog::operator=(const Animal& rhs)
{
	std::cout << "Opérateur d'assignation appelé.";
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf\n";
}