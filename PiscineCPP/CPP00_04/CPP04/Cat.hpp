/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:58:00 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:41:50 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string animalType);
	Cat(const Animal &other);
	Cat& operator=(const Animal& rhs);
	void makeSound() const;
	~Cat();
};