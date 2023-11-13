/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:50 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 20:59:52 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog "), DogBrain(new Brain())
{
	std::cout << "Constructeur par défaut de Dog." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructeur de Dog." << std::endl;
	delete	DogBrain;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Constructeur de copie de Dog.\n";
	this->DogBrain = new Brain();
	*this = other;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Opérateur d'assignation appelé.\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete(this->DogBrain);
		this->DogBrain = new Brain(*rhs.DogBrain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf\n";
}