/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:17:57 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/01 14:02:29 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
	: _name("Default")
{
	std::cout << "Zombie " << _name << " has been created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has been destroyed." << std::endl;
}

void	Zombie::setName(std::string &name)
{
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << "Zombie " << _name << " says: Braaaiiinnnssss!" << std::endl;
}