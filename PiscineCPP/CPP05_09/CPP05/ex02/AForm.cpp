/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:28:41 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 09:52:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
		if (_gradeToExecute < 1 || _gradeToSign < 1)
			throw AForm::GradeTooHighException();
		else if (_gradeToExecute > 150 || _gradeToSign > 150)
			throw AForm::GradeTooLowExecption();
		else
			std::cout << "AForm " << _name << " created." << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm & AForm::operator=(AForm const & src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowExecption();
	
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw AForm::CanNotSign();
	else if (_gradeToExecute < executor.getGrade()) 
		throw AForm::GradeTooLowExecption();
	_executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& src)
{
    if (src.getSigned()) {
        out << "AForm " << src.getName() << " is signed";
    } else {
        out << "AForm " << src.getName() << " is not signed";
    }
    return out;
}