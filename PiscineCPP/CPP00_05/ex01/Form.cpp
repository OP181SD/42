/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:19:33 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/18 12:43:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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

Form::~Form()
{
	std::cout << "Destructeur de Form.\n";
}