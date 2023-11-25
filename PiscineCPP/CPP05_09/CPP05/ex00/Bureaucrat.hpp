/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:45:24 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 12:05:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);