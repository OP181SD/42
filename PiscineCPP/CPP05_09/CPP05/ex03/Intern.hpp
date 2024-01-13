/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:53 by yassine           #+#    #+#             */
/*   Updated: 2024/01/08 16:34:15 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class Intern
{
private:
	
public:
	Intern();
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
	~Intern();
	AForm *makeForm(std::string formName, std::string target);
};

