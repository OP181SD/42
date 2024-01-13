/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:10:44 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:43:20 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    std::cout << YELLOW << "Shrubbery creation form : \n" << RESET;
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat jacky("Jacky", 1);
    jacky.signForm(shrubbery);
    jacky.executeForm(shrubbery);
	
    std::cout << YELLOW << "Creation of a shrubbery...\n";
    shrubbery.execute(jacky);

    std::fstream file("home_shrubbery", std::fstream::in);
    std::cout << "\n";
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
            std::cout << GREEN << line << std::endl << RESET;
        file.close();
        std::cout << "\n";
        std::cout << GREEN << "Shrubbery created successfully.\n" << RESET;
    }
    else
    {
        std::cout << RED << "Error opening file.\n" << RESET;
    }

    std::cout << PURPLE << "\nRobotomy request form : \n" << RESET;
    RobotomyRequestForm robotomy("Bender");
    Bureaucrat gisel("Gisel", 2); 
    gisel.signForm(robotomy);
    std::cout << YELLOW << "Robotomy in progress...\n" << RESET;
    gisel.executeForm(robotomy);
    std::cout << "\n";	
    robotomy.execute(gisel);
	
    std::cout << BLUE << "\nPresidential pardon form : \n" << RESET;
    PresidentialPardonForm presidential("President");
    Bureaucrat jacky2("Jacky", 1);
    jacky2.signForm(presidential);
    jacky2.executeForm(presidential);
    presidential.execute(jacky2);

    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        gisel.signForm(*rrf);
        gisel.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}

