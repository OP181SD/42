/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:42:53 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 15:59:45 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
	virtual void _executeAction() const = 0;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(AForm const & other);
	AForm &operator=(AForm const & rhs);
	virtual ~AForm();
	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	// Setters
	void setSigned(bool signedValue);
	// Methods
	void beSigned(Bureaucrat const & bureaucrat);
	void execute(Bureaucrat const & executor) const;
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
	class CanNotSign : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("CanNotSign.");
			}
	};

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);
