/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:04 by yassine           #+#    #+#             */
/*   Updated: 2023/11/22 08:02:17 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
  private:
	std::string const _name;
	int _grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	// Execption
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	// Getters
	std::string getName() const;
	int getGrade();
	// Methode;
	void GradeRange(int grade);
	void incrementelow();
	void incrementehigh();
	void signForm(AForm &form);
	friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
};