/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:57 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 21:00:59 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat "), CatBrain(new Brain())
{
	std::cout << "Constructeur par défaut de Cat." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructeur de Cat." << std::endl;
	delete	CatBrain;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Constructeur de copie de Cat.\n";
	this->CatBrain = new Brain();
	*this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Opérateur d'assignation appelé.\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete(this->CatBrain);
		this->CatBrain = new Brain(*rhs.CatBrain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meowww\n";
}