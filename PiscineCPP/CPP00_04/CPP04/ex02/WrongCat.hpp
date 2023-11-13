/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:34 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/13 18:13:25 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

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
	~WrongCat();
	void makeSound() const;
	std::string getType() const;
};
