/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/19 12:50:18 by yassine          ###   ########.fr       */
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
	std::cout << "----------------------------------------------";
	std::cout << "\n";
	RangeHighBoss();
	RangeLowLooser();
	Bureaucrat bureaucrat;
	std::cout << "-------------- Sous Chef aka Mr 1 ----------------\n";
	Form form("Mr 1", 1, 1);
	try
	{
		bureaucrat.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat bureaucrat3;
	std::cout << "-------------- Mr 3 ----------------\n";
	Form form3("Mr 3", 3, 3);
	try
	{
		bureaucrat3.signForm(form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}