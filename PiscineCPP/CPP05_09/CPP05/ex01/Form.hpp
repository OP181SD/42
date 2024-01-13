/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:19:37 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 13:56:43 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const & other);
	Form &operator=(Form const & rhs);
	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	// Setters
	void setSigned(bool signedValue);
	// Methods
	void beSigned(Bureaucrat const & bureaucrat);
	// Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high.");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low.");
			}
	};
	~Form();
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);