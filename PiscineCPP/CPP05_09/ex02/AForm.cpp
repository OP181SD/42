/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:19:33 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/19 10:40:57 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
	: _name("Uknow"), _signed(false), _grade(1), _grade_exec(1)
{
	std::cout << "Constructeur par defaut\n";
}

AForm::AForm(std::string name, int grade, int grade_exec)
	: _name(name), _grade(grade), _grade_exec(grade_exec)
{
	std::cout << "AFormulaire\n";
	GetFromRange(grade, grade_exec);
	_grade_exec = grade_exec;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _grade(other._grade), _grade_exec(other._grade_exec)
{
	std::cout << "Constructeur de copie de AForm.\n";
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned();
	return (*this);
}

void AForm::GetFromRange(int grade, int grade_exec)
{
	if (grade < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
	else
		_grade = grade;
}

void AForm::beSigned(Bureaucrat &signatory)
{
	if (_grade > signatory.getGrade())
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGrade() const
{
	return (_grade);
}

int AForm::getGradeExec() const
{
	return (_grade_exec);
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << "Name: " << obj._name << std::endl;
	out << "Status: " << (obj.getSigned() ? "Signed" : "Not Signed") << std::endl;
	out << "Grade required to sign: " << obj._grade << std::endl;
	out << "Grade required to execute: " << obj._grade_exec << std::endl;
	return (out);
}

AForm::~AForm()
{
	std::cout << "Destructeur de AForm.\n";
}