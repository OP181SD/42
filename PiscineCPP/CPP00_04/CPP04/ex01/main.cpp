/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 16:21:22 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

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
	std::cout << "...\n";
	std::cout << "----------------------------------------------\n";
	std::cout << "Remplacement par le WrongAnimal et le WrongCat : \n";
	std::cout << "----------------------------------------------\n";

	const WrongCat *wrongcat = new WrongCat();
	const WrongAnimal *k = new WrongAnimal();

	std::cout << "Création d'un WrongCat : " << wrongcat->getType() << std::endl;
	std::cout << "Création d'un WrongAnimal :" << k->getType() << std::endl;

	std::cout << "\nAppels de makeSound :\n";
	std::cout << "---------------------\n";

	std::cout << "WrongCat : ";
	wrongcat->makeSound();
	std::cout << "WrongAnimal : ";
	k->makeSound();

	std::cout << "...\n";
	std::cout << "----------------------------------------------\n";
	std::cout << "Construction des classes Dog et Cat avec new Brain : \n";
	std::cout << "----------------------------------------------\n";

	Brain *_Brain = new Brain();

	delete meta;
	delete i;
	delete j;
	delete k;
	delete wrongcat;
	delete _Brain;
	return (0);
}