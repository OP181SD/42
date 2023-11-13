/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:59 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 15:52:39 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(std::string BrainType);
	Brain(const Brain &cpy);
	Brain &operator=(const Brain &rhs);
	~Brain();
	std::string getType() const;
};
