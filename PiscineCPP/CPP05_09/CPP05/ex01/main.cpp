/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:56:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 09:53:05 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Gwendoline("Gwendoline", 2);
        Form form1("Form1", 5, 10);
        Gwendoline.signForm(form1); 
        std::cout << form1;
		
        Bureaucrat Geraltine("Geraltine", 150);
        Form form2("Form2", 100, 120); 
        Geraltine.signForm(form2);
        std::cout << form2;

        Bureaucrat Giselle("Giselle ", 0);
        Bureaucrat Jacky("Jacky ", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}