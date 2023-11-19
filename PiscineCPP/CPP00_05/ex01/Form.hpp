/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:18:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/19 09:21:19 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

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
	void GetFromRange(int grade, int grade_exec);
	void beSigned(Bureaucrat &signatory);
	friend std::ostream &operator<<(std::ostream &out, const Form &obj);
	// Getters
	bool getSigned() const;
	std::string getName() const;
	int getGrade() const;
	int getGradeExec() const;

  private:
	std::string _name;
	bool _signed;
	int _grade;
	int _grade_exec;
};
