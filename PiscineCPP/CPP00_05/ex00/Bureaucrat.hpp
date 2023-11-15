/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:04 by yassine           #+#    #+#             */
/*   Updated: 2023/11/15 12:51:26 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#pragma once

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();
 
    std::string getName() const;
    int getGrade();
	friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
private:
    std::string const _name;
    int _grade;
    int incremente_high_grade;
    int incremente_low_grade;
};

