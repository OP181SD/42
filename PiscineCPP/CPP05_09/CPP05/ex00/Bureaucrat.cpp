/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:05 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 13:25:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		setGrade(grade);	
}

Bureaucrat::Bureaucrat(Bureaucrat const & other)
{
	*this = other;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

void Bureaucrat::incrementGrade(int grade)
{
	setGrade(grade - 1);
}

void Bureaucrat::decrementGrade(int grade)
{
	setGrade(grade + 1);
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}