/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:18:33 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:33:03 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Constructeur par défault de FragTrap" << std::endl;
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;	
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap est né ! Il hérite des attributs de ClapTrap" << std::endl;
	EnergyPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;	
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "Constructeur de copie de FragTrap appelé" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructeur de FragTrap appelé" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "Opérateur d'assignation de FragTrap appelé" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (HitPoints == 0 || EnergyPoints == 0) {
        std::cout << "FragTrap est hors service et ne peut pas attaquer." << std::endl;
        return;
    }
    std::cout << "FragTrap à " << HitPoints << " PV, il se prépare à attaquer..." << std::endl;
    std::cout << "BAM!!! " << target << " a perdu " << AttackDamage << " HP." << std::endl;
    std::cout << "Cela coûte à FragTrap 1 point d'énergie." << std::endl;
    EnergyPoints -= 1;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five Made in FragTrap" << std::endl;
}