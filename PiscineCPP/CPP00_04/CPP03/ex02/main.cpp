/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:37:22 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
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
	std::cout << "\n";
    fragTrap.takeDamage(25);
	std::cout << "\n";
    fragTrap.beRepaired(3);
	std::cout << "--------------------------------\n";
    fragTrap.highFivesGuys();
	std::cout << "--------------------------------\n";
	std::cout << "\n";
    std::cout << "=== Fin des tests avec FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
    std::cout << "=== Avant la destruction de FragTrap ===" << std::endl;
	std::cout << "--------------------------------\n";
    return 0;
}
