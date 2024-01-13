/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:20:26 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 14:23:54 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGH_GRADE || gradeToExecute < HIGH_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > LOW_GRADE || gradeToExecute > LOW_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & other) 
: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this  = other;
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <=  _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

void Form::setSigned(bool signedValue)
{
	_signed = signedValue;
}

Form::~Form()
{
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	if (rhs.getSigned())
		o << "Formular : " << rhs.getName() << " as been is signed." << std::endl;
	else
		o << "Form " << rhs.getName() << " is not signed." << std::endl;
	return (o);	
}