/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:13:30 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 09:53:04 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
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
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		Name = rhs.Name;
		HitPoints = rhs.HitPoints;
        EnergyPoints = rhs.EnergyPoints;
        AttackDamage = rhs.AttackDamage;
	}
	return (*this);
}

void  ScavTrap::guardGate()
{
	std::cout << "ScavTrap est en mode gardien de la porte." << std::endl;
}