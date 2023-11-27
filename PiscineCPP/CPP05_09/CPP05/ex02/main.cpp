/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:56:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 14:08:04 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    srand(time(NULL));

    Bureaucrat gwendoline("Gwendoline", 5);
    Bureaucrat jacky("Jacky", 45);
    Bureaucrat mathilde("Mathilde", 137);

    ShrubberyCreationForm shrubbery("home");
    PresidentialPardonForm pardon("Stephen Bannon");
    RobotomyRequestForm robotomy("Bender");

    gwendoline.signAForm(shrubbery);
    gwendoline.executeForm(shrubbery);

    jacky.signAForm(pardon);
    jacky.executeForm(pardon);

    mathilde.signAForm(robotomy);
    mathilde.executeForm(robotomy);
}


