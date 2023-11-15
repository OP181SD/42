/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/15 12:50:55 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) , _grade(other._grade)
{
	std::cout << "Constructeur de copie du Bureaucrat.\n";
	*this = other;
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

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj._name << ", bureaucrat grade " << obj._grade;
	return (out);
}