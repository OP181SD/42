/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:16:12 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/01 10:34:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>

#pragma once

class Zombie
{
  public:
	void announce();
	void randomChump(std::string name);
	Zombie *newZombie(std::string name);
	Zombie(std::string name);
	~Zombie();

  private:
	std::string _name;
};
