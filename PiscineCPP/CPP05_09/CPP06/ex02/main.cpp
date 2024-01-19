/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:46:54 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/18 12:00:04 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A generated\n";
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << "B generated\n";
		return (new B());
	}
	else
		std::cout << "C generated\n";
	return (new C());
}

void	identify(Base *p)
{
	A	*pa;
	B	*pb;
	C	*pc;

	pa = dynamic_cast<A *>(p);
	pb = dynamic_cast<B *>(p);
	pc = dynamic_cast<C *>(p);
	if (pa != NULL)
		std::cout << "A\n";
	else if (pb != NULL)
		std::cout << "B\n";
	else if (pc != NULL)
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
		return ;
	}
	catch (const std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B\n";
		return ;
	}
	catch (const std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C\n";
		return ;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unknown\n";
	}
}

int	main(void)
{
	A	AInstance;
	B	BInstance;

	Base &ref = BInstance;
	std::cout << "Identify by pointer:" << std::endl;
	identify(&AInstance);
	std::cout << "\nIdentify by reference:" << std::endl;
	identify(ref);
	return (0);
}
