/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:51:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/09 20:01:14 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    std::string target = "BadTrap";
    clapTrap.attack(target);
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    return 0;
}