/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 20:22:54 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
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
	std::cout << "----------------------------------------------\n";
	std::cout << "le WrongAnimal et le WrongCat : \n";
	std::cout << "----------------------------------------------\n";

	
	const WrongAnimal *wrongcat = new WrongCat();
	const WrongAnimal *wronganimal = new WrongAnimal();

	std::cout << "\n";
	std::cout << "Création d'un WrongCat : " << wrongcat->getType() << std::endl;
	std::cout << "Création d'un WrongCat : " << wronganimal->getType() << std::endl;

	std::cout << "\nAppels de makeSound :\n";
	std::cout << "---------------------\n";

	std::cout << "WrongCat : ";
	wrongcat->makeSound();
	std::cout << "WrongAnimal : ";
	wronganimal->makeSound();

	std::cout << "\n";

	delete meta;
	delete i;
	delete j;
	delete wrongcat;
	delete wronganimal;
	return (0);
}