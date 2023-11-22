/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/22 08:00:40 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	GradeRange(grade);
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
	std::cout << "Destructeur du Bureaucrat.\n";
}

void Bureaucrat::GradeRange(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

void Bureaucrat::incrementelow()
{
	if (_grade > 1)
		_grade--;
}

void Bureaucrat::incrementehigh()
{
	if (_grade < 150)
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh.");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow.");
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[1;34m" << *this << " signed " << form << "\033[0m" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << "\033[1;31m cannot sign " << form << " because   \033[0m", throw GradeTooLowException();

	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj._name << ", bureaucrat grade " << obj._grade;
	return (out);
}
