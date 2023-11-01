/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:13:58 by yassine           #+#    #+#             */
/*   Updated: 2023/10/25 19:15:31 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once 

class Weapon
{
private:
    std::string _type;
public:
    std::string getType(void);
    void setType(const std::string& type);
    Weapon(std::string type);
    ~Weapon();
};
