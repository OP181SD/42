/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:36:30 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/01 10:34:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is destroyed." << std::endl;
}

Zombie	*newZombie(std::string name)
{
	Zombie *add = new Zombie(name);
	return (add);
}