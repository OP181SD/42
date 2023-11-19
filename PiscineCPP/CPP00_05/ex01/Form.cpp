/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:19:33 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/19 08:25:29 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
	: _name("Uknow"), _signed(), _grade(1), _grade_exec(1)
{
	std::cout << "Constructeur par defaut\n";
}

Form::Form(std::string name, int grade, int grade_exec)
	: _name(name), _grade(grade), _grade_exec(grade_exec)
{
	std::cout << "Constructeur avec des attribut\n";
	if (grade > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
	: _name(other._name), _grade(other._grade), _grade_exec(other._grade_exec)
{
	std::cout << "Constructeur de copie de Form.\n";
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned();
	return (*this);
}

void Form::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() >= 1)
	{
		_signed = true;
		signatory.signFrom();
	}
	else if (signatory.getGrade() > 150)
		Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGrade() const
{
	return (_grade);
}

int Form::getGradeExec() const
{
	return (_grade_exec);
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "Name: " << obj._name << std::endl;
	if (obj._signed)
		out << "Status: Signed" << std::endl;
	else
		out << "Status: Not Signed" << std::endl;
	out << "Grade required to sign: " << obj._grade << std::endl;
	out << "Grade required to execute: " << obj._grade_exec << std::endl;
	return (out);
}

Form::~Form()
{
	std::cout << "Destructeur de Form.\n";
}