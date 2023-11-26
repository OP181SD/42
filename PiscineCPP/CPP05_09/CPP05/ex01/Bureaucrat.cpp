/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:51:45 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 16:03:32 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(1)
{
	std::cout << "Constructeur du Bureaucrat.\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	: _name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructeur du Bureaucrat.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
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

void Bureaucrat::Incrementevalue()
{
	if (_grade < 150)
		_grade++;
}

void Bureaucrat::Decrementevalue()
{
	if (_grade > 1)
		_grade--;
}

void Bureaucrat::signForm(Form& s) 
{
    try {
        s.beSigned(*this);
        std::cout << _name << " signed " << s.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << _name << " couldn’t sign " << s.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}
