/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:03:32 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:16:13 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    Name("ClapTrap"), HitPoints(100), EnergyPoints(100), AttackDamage(30)
{
    std::cout << "Constructeur par défaut de ClapTrap appelé" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
    Name(name), HitPoints(100), EnergyPoints(30), AttackDamage(30)
{}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Constructeur de copie de ClapTrap appelé" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs) 
    {
        Name = rhs.Name;
        HitPoints = rhs.HitPoints;
        EnergyPoints = rhs.EnergyPoints;
        AttackDamage = rhs.AttackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructeur de ClapTrap appelé" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints == 0 || EnergyPoints == 0) {
        std::cout << "ClapTrap est hors service et ne peut pas attaquer." << std::endl;
        return;
    }
    std::cout << "ClapTrap à " << HitPoints << " PV, il se prépare à attaquer..." << std::endl;
    std::cout << "BAM!!! " << target << " a perdu " << AttackDamage << " HP." << std::endl;
    std::cout << "Cela coûte à ClapTrap 1 point d'énergie." << std::endl;
    EnergyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints <= 0 || EnergyPoints <= 0) 
	{
        std::cout << "ClapTrap est hors service." << std::endl;
		return;
    }
    if (HitPoints >= 1) {
        HitPoints -= amount;
        std::cout << "ClapTrap subit " << amount << " points de dégâts." << std::endl;
    } else {
        HitPoints = 0;
        std::cout << "ClapTrap ne peut plus encaisser de dégâts." << std::endl;
    }
	if (HitPoints <= 0 || EnergyPoints <= 0) {
        std::cout << "Game Over" << std::endl;
		return;
    }
    std::cout << "ClapTrap | HP : " << HitPoints << " | Énergie : " << EnergyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0 || EnergyPoints <= 0) {
        std::cout << "Game Over" << std::endl;
		return;
    }
    std::cout << "ClapTrap se répare, cela coûte 1 point d'énergie." << std::endl;
    if (EnergyPoints >= 1) {
        EnergyPoints -= 1;
        if ((unsigned int) HitPoints + amount <= 10)
		{
            HitPoints += amount;
            std::cout << "ClapTrap récupère " << amount << " PV." << std::endl;
        }
		else
			  std::cout << "ClapTrap est déjà au maximum de PV." << std::endl;
    } else {
        std::cout << "ClapTrap n'a pas assez d'énergie pour se réparer." << std::endl;
    }
    std::cout << "ClapTrap | HP : " << HitPoints << " | Énergie : " << EnergyPoints << std::endl;

    if (HitPoints <= 0 || EnergyPoints <= 0) {
        std::cout << "ClapTrap est hors service." << std::endl;
		return;
    }
}