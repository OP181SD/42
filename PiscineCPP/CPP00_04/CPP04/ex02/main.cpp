/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 17:49:28 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    std::cout << "----------------------------------------------\n";
    std::cout << "Construction des classes Animal, Dog et Cat avec new Brain : \n";
    std::cout << "----------------------------------------------\n";

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "Création d'un Dog : " << j->getType() << std::endl;
    std::cout << "Création d'un Cat : " << i->getType() << std::endl;

    std::cout << "----------------------------------------------\n";
    std::cout << "Construction des classes Animal, Dog et Cat avec new Brain : \n";
    std::cout << "----------------------------------------------\n";

    Animal *AnimalObject[5];
    for (int k = 0; k < 5; k++)
    {
        if (k % 2 == 0)
        {
            AnimalObject[k] = new Cat();
        }
        else
        {
            AnimalObject[k] = new Dog();
        }
    }

    std::cout << "----------------------------------------------\n";
    std::cout << "Affichage des types des objets dans AnimalObject : \n";
    std::cout << "----------------------------------------------\n";

    for (int k = 0; k < 5; k++)
    {
        std::cout << "AnimalObject[" << k << "] : " << AnimalObject[k]->getType() << std::endl;
    }

    std::cout << "----------------------------------------------\n";
    std::cout << "Suppression des objets dans AnimalObject : \n";
    std::cout << "----------------------------------------------\n";

    for (int k = 0; k < 5; k++)
    {
        delete AnimalObject[k];
    }

    delete j;
    delete i;

    return 0;
}
