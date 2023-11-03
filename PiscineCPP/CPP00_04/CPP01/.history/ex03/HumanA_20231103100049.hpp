/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:30:02 by yassine           #+#    #+#             */
/*   Updated: 2023/11/01 14:11:12 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#pragma once 

class HumanA
{
public:
    void attack();
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
private:
    std::string _name;
    Weapon _weapon;
};

