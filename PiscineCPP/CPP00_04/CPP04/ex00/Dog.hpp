/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:03:44 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:41:40 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string animalType);
	Dog(const Animal &other);
	Dog& operator=(const Animal& rhs);
	void makeSound() const;
	~Dog();
};