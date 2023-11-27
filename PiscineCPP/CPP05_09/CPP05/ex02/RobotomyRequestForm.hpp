/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:28:02 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 10:29:52 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
	~RobotomyRequestForm();
};
