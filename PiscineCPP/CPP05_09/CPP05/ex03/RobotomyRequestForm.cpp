/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:53:40 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:19:22 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm ::RobotomyRequestForm () : AForm("default", 72, 45)
{}

RobotomyRequestForm ::RobotomyRequestForm (std::string target) : AForm("RobotomyRequestForm ", 72, 45), _target(target)
{}

RobotomyRequestForm ::RobotomyRequestForm (RobotomyRequestForm  const & other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm ::~RobotomyRequestForm ()
{}

RobotomyRequestForm  & RobotomyRequestForm ::operator=(RobotomyRequestForm  const & rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::_executeAction() const 
{
    std::srand(std::time(NULL));
    std::cout <<   YELLOW << "Drilling noises... " << RESET;
    if (std::rand() % 2 == 0)
        std::cout << GREEN << _target << " has been robotomized successfully!" << RESET << std::endl;
	 else
        std::cout << RED << "Robotomy failed for " << _target << "." <<  RESET << std::endl;
}