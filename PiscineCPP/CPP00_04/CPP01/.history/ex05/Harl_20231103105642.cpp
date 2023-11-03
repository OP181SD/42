/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:08:51 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/03 10:56:42 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::complain(const std::string &level)
{
			Harl instance;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr_function_member[4])(void) = {
		&Harl::Debug,
		&Harl::Info,
		&Harl::Warning,
		&Harl::Error};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(instance.*ptr_function_member[i])();
			break ;
		}
	}
}

void Harl::Debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::Info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did,
		I wouldn't be asking for more!" << std::endl;
}

void Harl::Warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::Error()
{
	std::cout << "This is unacceptable,
		I want to speak to the manager now." << std::endl;
}