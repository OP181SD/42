/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExecute;

	virtual void _executeAction() const = 0;
public:
	// Canonical AForm
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(AForm const & src);
	AForm & operator=(AForm const & src);
	virtual ~AForm();
	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	// Methods
	void beSigned(Bureaucrat & bureaucrat);
	void execute(Bureaucrat const & executor) const;
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
	class CanNotSign : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("CanNotSign.");
			}
	};
};
std::ostream& operator<<(std::ostream& out, const AForm& obj);