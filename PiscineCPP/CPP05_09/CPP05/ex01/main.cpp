/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:10:44 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 14:38:29 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << YELLOW << "if the bureaucrat grade his Higer than the GradeToSign : " << RESET << std::endl;
		Bureaucrat jacky("Jacky", 1);
		std::cout << GREEN << jacky;
		Form form("Form1", 3, 1);
		form.beSigned(jacky);
		std::cout << form;
		jacky.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << YELLOW << "if the bureaucrat grade his Lower than the GradeToSign : " << RESET << std::endl;
		Bureaucrat Gisel("Gisel", 120);
		std::cout << RED << Gisel;
		Form form("Form2", 3, 1);
		std::cout << form;
		Gisel.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
