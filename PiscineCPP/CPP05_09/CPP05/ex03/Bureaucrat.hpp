/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:11 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:19:58 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Grade 1 is the highest, 150 the lowest
#define HIGH_GRADE 1
#define LOW_GRADE 150

//Color 
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PURPLE "\033[0;35m"

// Libraries
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

// Classes
class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int					_grade;
public:
	// Canonical Form
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & other);
	Bureaucrat &operator=(Bureaucrat const & rhs);
	// Getters
	std::string getName() const;
	int getGrade() const;
	// Setters
	void setGrade(int grade);
	// Methods
	void incrementGrade(int grade);
	void decrementGrade(int grade);
	void signForm(AForm & Aform);
	void executeForm(AForm const & form);
	// Destructor
	~Bureaucrat();
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
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);
	