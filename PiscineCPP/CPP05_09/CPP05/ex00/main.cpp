/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:10:44 by yassine           #+#    #+#             */
/*   Updated: 2024/01/07 16:35:24 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
	try
	{
		std::cout << BLUE << "Creating a bureaucrat with grade 1 "  << RESET << std::endl;
		Bureaucrat jacky("Jacky", 0);
		std::cout << jacky;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error : " << e.what() << RESET << '\n';
	}
	
	try
	{
		std::cout << BLUE << "Creating a bureaucrat with grade 151 " << RESET << std::endl;
		Bureaucrat Gisel("Gisel", 151);
		std::cout << Gisel;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error : " << e.what() << RESET << '\n';
	}
	
	try
	{
		std::cout << BLUE << "Creating a bureaucrat with grade 3" << RESET << std::endl;
		Bureaucrat Gisel("Gisel", 3);
		Gisel.incrementGrade(Gisel.getGrade());
		std::cout << GREEN << Gisel;
	}
	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << BLUE << "Creating a bureaucrat with grade 149" << RESET << std::endl;
		Bureaucrat Gisel("Gisel", 149);
		Gisel.decrementGrade(Gisel.getGrade());
		std::cout  << GREEN << Gisel;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
