/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:57 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:45:41 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Constructeur par défaut de Cat." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructeur de Cat." << std::endl;
}

Cat::Cat(std::string animalType) : Animal(animalType)
{
	std::cout << "Constructeur Cat qui hérite de la class Animal" << std::endl;
}

Cat::Cat(const Animal &other) : Animal(other) 
{
	std::cout << "Constructeur de copie de Cat.\n";
}

Cat& Cat::operator=(const Animal& rhs)
{
	std::cout << "Opérateur d'assignation appelé.";
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meoow\n";
}