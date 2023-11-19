/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/19 08:27:38 by yasaidi          ###   ########.fr       */
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
	displayHighGradeSection();
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
	return (0);
}