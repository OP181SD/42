/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:50:44 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/26 08:50:29 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class	Bureaucrat;

class Form
{
  private:
	std::string const _name;
	bool _signed;
	int const to_sign;
	int const to_exec;

  public:
	// Canonical Form
	Form();
	Form(std::string name, int grade_sign, int grade_exec);
	Form(const Form &src);
	Form &operator=(const Form &rhs);
	~Form();

	// Getters
	std::string getName(void) const;
	int getGrade() const;
	int getGradeExec() const;
	bool getSigned() const;

	// Member Functions
	void beSigned(Bureaucrat obj);

	// Execption
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("GradeTooHighException.");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("GradeTooLowException.");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);