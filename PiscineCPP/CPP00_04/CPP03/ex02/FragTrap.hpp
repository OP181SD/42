/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:06:01 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 17:32:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#pragma once 

class FragTrap : public ClapTrap
{	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();
	void highFivesGuys(void);
	void attack(const std::string& target);
};
