/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:40:04 by yassine           #+#    #+#             */
/*   Updated: 2023/11/01 14:01:48 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

class Zombie
{
  public:
	Zombie();
	~Zombie();
	void setName(std::string &name); 

	void announce(void);
  private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);
