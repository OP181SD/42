/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:13:58 by yassine           #+#    #+#             */
/*   Updated: 2023/11/03 10:15:10 by yasaidi          ###   ########.fr       */
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
    void setType(std::string& type);
    Weapon(std::string type);
    ~Weapon();
};
