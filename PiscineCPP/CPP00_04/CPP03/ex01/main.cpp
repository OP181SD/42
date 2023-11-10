/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:39:23 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Tests avec ClapTrap ===" << std::endl;
    std::cout << "--------------------------\n";
    ClapTrap clapTrap("ClapTrapOriginal");
    std::string target = "BadTrap";
    clapTrap.attack(target);
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    std::cout << "\n";

    std::cout << "=== Tests avec ScavTrap ===" << std::endl;
    std::cout << "--------------------------\n";
    ScavTrap scavTrap("ScavTrap");
    std::string scavTarget = "ScavBadTrap";
    scavTrap.attack(scavTarget);
    scavTrap.takeDamage(3);
    scavTrap.beRepaired(2);
    scavTrap.guardGate();

    return 0;
}




