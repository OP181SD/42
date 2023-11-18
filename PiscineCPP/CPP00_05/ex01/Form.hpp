/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:18:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/18 17:36:11 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
  public:
	Form();
	Form(std::string name, int grade, int grade_exec);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();
	// Execption
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade Too High");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade Too Loow");
		}
	};
	// Methode
	void GetFromRange(int grade);
	// Getters
	bool GetSigned() const;
	std::string GetName() const;
	int GetGrade() const ;
	int GetGradeExec() const;
	void beSigned(Bureaucrat &signatory);
	
  private:
	std::string const _name;
	bool _signed;
	int const _grade;
	int const _grade_exec;
};
