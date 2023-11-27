/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:28:52 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 09:42:21 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExecute;

public:
	// Canonical Form
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const & src);
	Form & operator=(Form const & src);
	~Form();
	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	// Methods
	void beSigned(Bureaucrat & bureaucrat);
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
std::ostream& operator<<(std::ostream& out, const Form& obj);