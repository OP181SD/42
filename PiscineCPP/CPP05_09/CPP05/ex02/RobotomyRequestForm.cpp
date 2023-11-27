/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 10:27:39 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
