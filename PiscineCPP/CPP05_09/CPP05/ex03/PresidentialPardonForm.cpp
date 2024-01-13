/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:46:57 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:22:10 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::_executeAction() const
{
	std::cout  << GREEN << _target + " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}