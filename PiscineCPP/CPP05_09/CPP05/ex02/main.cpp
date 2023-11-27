/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:56:09 by yassine           #+#    #+#             */
/*   Updated: 2023/11/27 10:23:23 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat Gwendoline("Gwendoline", 2);
        AForm Aform1("AForm1", 5, 10);
        Gwendoline.signAForm(Aform1); 
        std::cout << Aform1;
		
        Bureaucrat Geraltine("Geraltine", 150);
        AForm Aform2("AForm2", 100, 120); 
        Geraltine.signAForm(Aform2);
        std::cout << Aform2;

        Bureaucrat Giselle("Giselle ", 0);
        Bureaucrat Jacky("Jacky ", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}