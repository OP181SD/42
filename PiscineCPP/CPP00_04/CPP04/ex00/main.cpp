/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 10:57:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Création d'un Animal : " << meta->getType() << std::endl;
	std::cout << "Création d'un Dog : " << j->getType() << std::endl;
	std::cout << "Création d'un Cat : " << i->getType() << std::endl;

	std::cout << "\nAppels de makeSound :\n";
	std::cout << "---------------------\n";

	std::cout << "Cat : ";
	i->makeSound();

	std::cout << "\nDog : ";
	j->makeSound();

	std::cout << "\nAnimal : ";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return (0);
}