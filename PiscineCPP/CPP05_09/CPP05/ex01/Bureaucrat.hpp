/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:45:24 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 15:38:13 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
  private:
	std::string const _name;
	int	_grade;

  public:
	// Canonical Form
	Bureaucrat();
	Bureaucrat(std::string  const name, int grade);
	Bureaucrat(Bureaucrat const  &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &rhs);
	
	// Getters
	std::string getName(void) const;
	int getGrade() const;
	
	// Member Functions
	void Incrementevalue();
	void Decrementevalue();
	void signForm(Form& s);

	// Execption
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Bureaucrat::GradeTooHighException");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Bureaucrat::GradeTooLowException.");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);