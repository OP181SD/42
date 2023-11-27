/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:30:41 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 10:33:33 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}
