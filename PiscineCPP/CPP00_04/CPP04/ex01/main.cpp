/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:52:49 by yassine           #+#    #+#             */
/*   Updated: 2023/11/13 19:32:00 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "Création d'un Dog : " << j->getType() << std::endl;
    std::cout << "Création d'un Cat : " << i->getType() << std::endl;


    Animal *AnimalObject[10];
    for (int k = 0; k < 10; k++)
    {
        if (k < 5 )
            AnimalObject[k] = new Cat();
        else
            AnimalObject[k] = new Dog();
    }
    for (int k = 0; k < 10; k++)
    {
        std::cout << "AnimalObject[" << k << "] : " << AnimalObject[k]->getType() << std::endl;
    }
    for (int k = 0; k < 10; k++)
    {
        delete AnimalObject[k];
    }
    
    delete j;
    delete i;
    return 0;
}
