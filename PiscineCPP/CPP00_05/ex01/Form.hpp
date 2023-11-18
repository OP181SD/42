/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:18:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/18 12:42:46 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form
{
  public:
	Form();
	Form(std::string name, int grade, int grade_exec);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();

  private:
	std::string const _name;
	bool _signed;
	int const _grade;
	int const _grade_exec;
};
