/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:28:41 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 09:52:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
		if (_gradeToExecute < 1 || _gradeToSign < 1)
			throw Form::GradeTooHighException();
		else if (_gradeToExecute > 150 || _gradeToSign > 150)
			throw Form::GradeTooLowExecption();
		else
			std::cout << "Form " << _name << " created." << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

Form & Form::operator=(Form const & src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

Form::~Form()
{}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowExecption();
}

std::ostream& operator<<(std::ostream& out, const Form& src)
{
    if (src.getSigned()) {
        out << "Form " << src.getName() << " is signed";
    } else {
        out << "Form " << src.getName() << " is not signed";
    }
    return out;
}