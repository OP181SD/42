/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB->cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:12:10 by yassine           #+#    #+#             */
/*   Updated: 2023/10/25 18:59:54 by yassine          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name)
{
    std::cout << "HumanB constructor Called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destructor Called" << std::endl;
}

void HumanB::setWeapon(Weapon& club)
{
   this->_weapon = &club;
}
void HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}