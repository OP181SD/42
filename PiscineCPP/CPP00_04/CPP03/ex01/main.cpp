/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 09:58:51 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    std::string target = "BadTrap";
    clapTrap.attack(target);
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    ScavTrap scavTrap("ScavTrap");
    std::string scavTarget = "Bandit";
    scavTrap.attack(scavTarget);
    scavTrap.takeDamage(4);
    scavTrap.beRepaired(3);
    scavTrap.guardGate();
    return 0;
}
