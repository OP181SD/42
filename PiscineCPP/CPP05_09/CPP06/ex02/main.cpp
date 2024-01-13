/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 08:44:24 by yassine           #+#    #+#             */
/*   Updated: 2024/01/13 08:48:13 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
	if (rand() % 3 == 0)
	{
		std::cout << "A generated" << std::endl;
		return (new A());
	}
	else if (rand() % 3 == 1)
	{
		std::cout << "B generated" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return (new C());
	}
}

void indentify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}		
	else
		std::cout << "Unknown" << std::endl;	
}