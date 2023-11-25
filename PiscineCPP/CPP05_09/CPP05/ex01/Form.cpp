/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:50:38 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 13:40:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("Default"), _signed(false), to_sign(150), to_exec(150)
{
}

Form::Form(std::string name, int grade_sign, int grade_exec)
	: _name(name), to_sign(grade_sign), to_exec(grade_exec)
{
}

Form::Form(const Form &src)
	: _name(src._name), to_sign(src.to_sign), to_exec(src.to_exec)
{
	*this = src;
}

Form &Form::operator=(const Form &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (_name);
}

int Form::getGrade() const
{
	return (to_sign);
}

int Form::getGradeExec() const
{
	return (to_exec);
}

bool Form::getSigned() const
{
	return (_signed);
}

void Form::beSigned(Bureaucrat obj)
{
	if (obj.getGrade() < 1)
		throw Form::GradeTooLowException();
	else if (obj.getGrade() > 150)
		throw Form::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "Name: " << obj.getName() << std::endl;
	out << "Status: " << (obj.getSigned() ? "Signed" : "Not Signed") << std::endl;
	out << "Grade required to sign: " << obj.getGrade() << std::endl;
	out << "Grade required to execute: " << obj.getGradeExec() << std::endl;
	return (out);
}