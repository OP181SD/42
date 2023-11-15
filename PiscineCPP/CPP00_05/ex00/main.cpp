/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/15 12:51:15 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    Bureaucrat bureaucrat;
    std::cout << "Name: " << bureaucrat.getName() << std::endl;
    std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;

    std::cout << "Details: " << bureaucrat << std::endl;

    return 0;
}