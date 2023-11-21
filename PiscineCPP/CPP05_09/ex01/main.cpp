/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/19 10:43:57 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	RangeHighBoss(void)
{
	displayHighGradeSection();
	try
	{
		Form Mr0("Mr 0", 0, 0);
		std::cout << Mr0 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	RangeLowLooser(void)
{
	displayLowGradeSection();
	try
	{
		Form Mr0("Mr 0", 151, 151);
		std::cout << Mr0 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	RangeHighBoss();
	RangeLowLooser();

	std::cout << "-------------- Bureaucrat ----------------\n";
	Bureaucrat bureaucrat("Mr Bureaucrat ", 1);
	std::cout << "-------------- Sous Chef aka Mr 1 ----------------\n";
	Form form("Mr 1", 1, 1);
	try
	{
		bureaucrat.signForm(form);
		std::cout << "------------------------------\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Afffichage du formulaire
	std::cout << form << std::endl;
	
	std::cout << "------------------------------\n";
	Bureaucrat bureaucrat3("Mr 3", 1);
	std::cout << "-------------- Random ----------------\n";
	Form form3("Mr 1", 3, 3);

	try
	{
		bureaucrat3.signForm(form3);
		std::cout << "------------------------------\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Afffichage du formulaire
	std::cout << form3 << std::endl;
	
	return (0);
}