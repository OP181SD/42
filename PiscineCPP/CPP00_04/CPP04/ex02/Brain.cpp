/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:55 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 17:46:41 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructeur par défaut de Brain." << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Constructeur de copie de Brain" << std::endl;
	*this = cpy;
}

Brain::~Brain()
{
	std::cout << "Destructeur de Brain." << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
		std::cout << "Opérateur d'assignation de Brain appelé (copie profonde)." << std::endl;
	}
	return (*this);
}