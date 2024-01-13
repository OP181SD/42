/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:45:02 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 15:57:22 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGH_GRADE || gradeToExecute < HIGH_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > LOW_GRADE || gradeToExecute > LOW_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & other) 
: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this  = other;
}

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <=  _gradeToSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::setSigned(bool signedValue)
{
	_signed = signedValue;
}

AForm::~AForm()
{
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw AForm::CanNotSign();
	else if (_gradeToExecute < executor.getGrade()) 
		throw AForm::GradeTooLowException();
	_executeAction();
}


std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
	if (rhs.getSigned())
		o << "AFormular : " << rhs.getName() << " as been is signed." << std::endl;
	else
		o << "AForm " << rhs.getName() << " is not signed." << std::endl;
	return (o);	
}
