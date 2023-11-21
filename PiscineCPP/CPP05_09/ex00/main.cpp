/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/21 10:41:51 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	displayHighGradeSection(void)
{
	std::cout << "==== Bureaucrat avec une note haute ====\n";
	std::cout << "---------------------------------------------\n";
}

void	displayLowGradeSection(void)
{
	std::cout << "==== Bureaucrat avec une note basse ====\n";
	std::cout << "---------------------------------------------\n";
}

void	Incrementation(void)
{
	std::cout << "\n";
	displayHighGradeSection();
	try
	{
		Bureaucrat Gwendoline("Gwendoline", 3);
		std::cout << Gwendoline << std::endl;
		Gwendoline.incrementelow();
		std::cout << "Après avoir incrémenté, Gwendoline a maintenant : " << Gwendoline << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	displayLowGradeSection();
	try
	{
		Bureaucrat Geraltine("Geraltine", 151);
		std::cout << Geraltine << std::endl;
		Geraltine.incrementehigh();
		std::cout << "Après avoir incrémenté Geraltine a maintenant : " << Geraltine << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	Incrementation();
	return (0);
}
