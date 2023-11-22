/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:18:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/22 08:01:38 by yassine          ###   ########.fr       */
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
	virtual ~AForm();
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
	virtual void beSigned(Bureaucrat &signatory) = 0; 
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
