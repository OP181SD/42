/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:55:38 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:42:22 by yassine          ###   ########.fr       */
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
	Animal& operator=(const Animal& rhs);
	void makeSound() const;
	std::string getType() const;
	virtual ~Animal();
};