/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:53:13 by yassine           #+#    #+#             */
/*   Updated: 2023/10/25 19:32:19 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main() {
    // Create a Weapon
    Weapon club = Weapon("crude spiked club");

    // Create HumanA (Bob) and make him attack
    HumanA bob("Bob", club);
    bob.attack();

    // Update the weapon type
    club.setType("some other type of club");

    // Bob attacks again with the updated weapon
    bob.attack();

    // Create HumanB (Jim) and make him attack
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();

    // Update the weapon type again
    club.setType("yet another type of club");

    // Jim attacks again with the updated weapon
    jim.attack();

    return 0;
}