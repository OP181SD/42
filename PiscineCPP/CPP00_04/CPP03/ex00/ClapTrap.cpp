/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:03:32 by yassine           #+#    #+#             */
/*   Updated: 2023/11/05 16:10:40 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    Name("ClapTrap"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
}

ClapTrap::ClapTrap(std::string name) : 
    Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{	
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    Name = other.Name;
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
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

}

void ClapTrap::attack(const std::string& target)
{
    std::cout << Name << " | HP | " << EnergyPoints << " vs " << target << " | HP | " << EnergyPoints << std::endl;
    std::cout << "ClapTrap attacks: BAM!!!" << std::endl;
    std::cout << "Target " << target << " loses " << AttackDamage + 1 << " HP" << std::endl;
    std::cout << Name << " | HP | " << EnergyPoints << " vs " << target << " | HP | " << (EnergyPoints - 1) << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << Name << " | HP | " << EnergyPoints << std::endl;
    std::cout << "ClapTrap is repairing itself, it costs 1 HP." << std::endl;

    if (EnergyPoints >= 1) {
        EnergyPoints -= 1;
        if ((unsigned int) HitPoints + amount <= 10) {
            HitPoints += amount;
            std::cout << Name << " regains " << amount << " HP." << std::endl;
        }
    } else {
        std::cout << Name << " doesn't have enough energy to repair itself." << std::endl;
    }

    std::cout << Name << " | HP | " << EnergyPoints << std::endl;
    std::cout << "--------- +1 HP -------" << std::endl;
    std::cout << "ClapTrap | HP | " << EnergyPoints + 1 << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints >= 1) {
        HitPoints -= amount;
        std::cout << Name << " takes " << amount << " damage." << std::endl;
    } else {
        HitPoints = 0;
        std:: cout << Name << " can't take any more damage." << std::endl;
    }
    std::cout << Name << " HP " << EnergyPoints << std::endl;
    EnergyPoints -= 1;
}
