/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:13:30 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 10:58:42 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Constructeur de ScavTrap appelé" << std::endl;
	
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap est né ! Il hérite des attributs de ClapTrap" << std::endl;	
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
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

ScavTrap::~ScavTrap()
{
	std::cout << "Destructeur de ScavTrap appelé" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints == 0 || EnergyPoints == 0) {
        std::cout << "ScavTrap est hors service et ne peut pas attaquer." << std::endl;
        return;
    }
    std::cout << "ScavTrap à " << HitPoints << " PV, il se prépare à attaquer..." << std::endl;
    std::cout << "BAM!!! " << target << " a perdu " << AttackDamage << " HP." << std::endl;
    std::cout << "Cela coûte à ScavTrap 1 point d'énergie." << std::endl;
    EnergyPoints -= 1;
}

void  ScavTrap::guardGate()
{
	std::cout << "ScavTrap est en mode gardien de la porte." << std::endl;
}