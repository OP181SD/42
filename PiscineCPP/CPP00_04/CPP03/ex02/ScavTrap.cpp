/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:13:30 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:15:46 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Constructeur de ScavTrap appelé" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructeur de ScavTrap appelé" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap est né ! Il hérite des attributs de ClapTrap" << std::endl;	
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Constructeur de copie de ScavTrap appelé" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "Opérateur d'assignation de ScavTrap appelé" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

void  ScavTrap::guardGate()
{
	std::cout << "ScavTrap est en mode gardien de la porte." << std::endl;
}