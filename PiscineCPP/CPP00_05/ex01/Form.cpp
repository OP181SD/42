/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:19:33 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/18 13:39:48 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
	: _name("DefaultForm"), _signed(false), _grade(1), _grade_exec(1)
{
	std::cout << "Constructeur par defaut\n";
}

Form::Form(std::string name, int grade, int grade_exec)
	: _name(name), _grade(grade), _grade_exec(grade_exec)
{
	std::cout << "Constructeur avec des attribut\n";
}

Form::Form(const Form &other)
	: _name(other._name), _grade(other._grade), _grade_exec(other._grade_exec)
{
	std::cout << "Constructeur de copie de Form.\n";
}



Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs.GetSigned();
}

bool Form::GetSigned() const
{
	return (_signed);
}

int Form::GetGrade() const
{
	return (_grade);
}

int Form::GetGradeExec() const
{
	return (_grade_exec);
}

Form::~Form()
{
	std::cout << "Destructeur de Form.\n";
}