/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:10:44 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:30:17 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	
    try
    {
        std::cout << YELLOW << "Shruberry creation form : \n" << RESET;
        ShrubberyCreationForm shrubbery("home");
        Bureaucrat jacky("Jacky", 1);
        jacky.signForm(shrubbery);
        jacky.executeForm(shrubbery);
		std::cout << YELLOW << "Creation of a shrubbery..\n";
		shrubbery.execute(jacky);
		std::fstream file;
		file.open("home_shrubbery", std::fstream::in);
		std::cout << "\n";
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
				std::cout << GREEN << line << std::endl << RESET;
			file.close();
		}
		else
			std::cout << RED << "Error opening file.\n" << RESET;
	
		std::cout << "\n";
		std::cout << GREEN << "Shrubbery created successfully.\n" << RESET;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << PURPLE << "\nRobotomy request form : \n" << RESET;
        RobotomyRequestForm robotomy("Bender");
        Bureaucrat gisel("Gisel", 2); 
        gisel.signForm(robotomy);
		std::cout << YELLOW << "Robotomy in progress..\n" << RESET;
        gisel.executeForm(robotomy);
		std::cout << "\n";	
		robotomy.execute(gisel);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    try
    {
        std::cout <<  BLUE << "\nPresidential pardon form : \n" << RESET;
        PresidentialPardonForm presidential("President");
        Bureaucrat jacky("Jacky", 1);
        jacky.signForm(presidential);
        jacky.executeForm(presidential);
		presidential.execute(jacky);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
