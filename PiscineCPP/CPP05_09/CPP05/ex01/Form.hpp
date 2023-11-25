/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:50:44 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 13:38:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return ("GradeTooHigh.");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("GradeTooLow.");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);