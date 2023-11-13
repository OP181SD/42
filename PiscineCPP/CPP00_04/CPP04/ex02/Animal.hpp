/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:55:38 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 21:03:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(std::string animalType);
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);
	virtual void makeSound() const = 0;
	virtual ~Animal();
	std::string getType() const;
};
