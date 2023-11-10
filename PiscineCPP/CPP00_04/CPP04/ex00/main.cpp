/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/10 18:48:18 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Création d'un Animal : " << meta->getType() << std::endl;
    std::cout << "Création d'un Dog : " << j->getType() << std::endl;
    std::cout << "Création d'un Cat : " << i->getType() << std::endl;

    std::cout << "\nAppels de makeSound :\n";
    std::cout << "---------------------\n";
    
    std::cout << "Cat : ";
    i->makeSound();  // Appelle la fonction makeSound de Cat

    std::cout << "\nDog : ";
    j->makeSound();  // Appelle la fonction makeSound de Dog

    std::cout << "\nAnimal : ";
    meta->makeSound();  // Appelle la fonction makeSound de Animal

    delete meta;
    delete j;
    delete i;

    return 0;
}