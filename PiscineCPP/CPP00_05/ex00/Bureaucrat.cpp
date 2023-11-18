/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/18 08:56:38 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name(""), _grade(1)
{
	std::cout << "Constructeur par défaut.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	std::cout << "Nom : " << name << std::endl;
	std::cout << "Grade : " << grade << std::endl;
	GradeRange(grade); e
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "Constructeur de copie du Bureaucrat.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructeur par défaut du Bureaucrat.\n";
}

void Bureaucrat::GradeRange(int grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	else
		_grade = grade;
}

void Bureaucrat::incrementelow()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooLowException();
		
}

void Bureaucrat::incrementehigh()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooHighException();
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj._name << ", bureaucrat grade " << obj._grade;
	return (out);
}
