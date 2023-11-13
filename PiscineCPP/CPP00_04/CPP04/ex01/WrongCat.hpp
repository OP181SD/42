/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:34 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 14:24:55 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

#pragma once

class WrongCat 
{
  protected:
	std::string type;

  public:
	WrongCat();
	WrongCat(std::string wrongCat);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &rhs);
	virtual ~WrongCat();
	virtual void makeSound() const;
	std::string getType() const;
};