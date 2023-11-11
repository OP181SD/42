/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/11 09:42:43 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "=== Avant la création de FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
	ClapTrap clapTrap("ClapTrapOriginal");
	std::string target = "BadFragTrap";
	std::cout << "Launching FragTrap...\n";
	std::cout << "--------------------------------\n";
	std::cout << "=== Après la création de FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
	FragTrap fragTrap("FragTrap");
	std::cout << "=== Tests avec FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
	fragTrap.attack(target);
	std::cout << "--------------------------------\n";
	fragTrap.highFivesGuys();
	std::cout << "--------------------------------\n";
	std::cout << "\n";
	std::cout << "=== Fin des tests avec FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
	std::cout << "=== Avant la destruction de FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
	return (0);
}
