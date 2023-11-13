/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:08:23 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 20:18:49 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class WrongAnimal
{
  protected:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(std::string WrongAnimal);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};
