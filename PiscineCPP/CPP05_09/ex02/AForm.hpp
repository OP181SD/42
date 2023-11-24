/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:18:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/24 11:00:08 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
  public:
	AForm();
	AForm(std::string name, int grade, int grade_exec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);
	 ~AForm();
	// Execption
	class GradeTooHighException : public std::exception
	{
		public:
		 const char *what() const throw()
		{
			return ("Grade Too High");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		 const char *what() const throw()
		{
			return ("Grade Too Loow");
		}
	};
	// Methode
	void GetFromRange(int grade, int grade_exec);
	 void beSigned(Bureaucrat &signatory);
	friend std::ostream &operator<<(std::ostream &out, const AForm &obj);
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
