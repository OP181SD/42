/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:12:52 by yassine           #+#    #+#             */
/*   Updated: 2023/10/25 19:30:26 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#pragma once 

class HumanB
{
public:
    void attack();  
    HumanB(const std::string& name);
    void setWeapon(Weapon &club);
    ~HumanB();
private:
    std::string _name;
    Weapon* _weapon;
};
