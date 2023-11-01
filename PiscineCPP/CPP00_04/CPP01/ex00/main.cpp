/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:14:43 by yassine           #+#    #+#             */
/*   Updated: 2023/11/01 10:33:55 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Creating a Zombie on the Heap" << std::endl;
	Zombie *heapZombie = new Zombie("I am a new object on the heap");
	heapZombie->announce();

	std::cout << "Creating a Zombie on the Stack" << std::endl;
	Zombie stackZombie = Zombie("I am a new object on the stack now!");
	stackZombie.announce();
	delete heapZombie;
	return (0);
}