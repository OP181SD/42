/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:34:12 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 13:13:36 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	// Canonical Form
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & src);
	~Bureaucrat();
	// Getters
	std::string getName() const;
	int getGrade() const;
	// Methods
	void incrementGrade();
	void decrementGrade();
	void signAForm(AForm & Aform);
	void executeForm(AForm const & form) const;
	// Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Grade is too high.");
			}
	};
	class GradeTooLowExecption : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Grade is too low.");
			}
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);