/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:03:44 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 17:49:54 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
  Brain *DogBrain;
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	void makeSound() const;
	~Dog();
};