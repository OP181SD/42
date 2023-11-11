/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/11 09:42:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
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
	scavTrap.guardGate();
	return (0);
}
