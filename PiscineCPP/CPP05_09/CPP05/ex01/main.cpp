/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:27:15 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/26 14:00:18 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat Chloé("Chloé", 24);
    Form Formulaire1("Formulard 1", 24, 24); 
    Form Formulaire2("Formulard 2", 13, 13); 

    try {
        std::cout << "Trying to create Form3...\n";
        Form Formulaire3("Formulard 3 ", 0, 151); 
    }
    catch (const std::exception& e) {
        std::cout << "Couldn't create Form3: " << e.what() << std::endl;
    }

    std::cout << "\nSigning Form1...\n";
    Chloé.signForm(Formulaire1); 
    std::cout << "Signing Form2...\n";
    Chloé.signForm(Formulaire2);
    return 0;
}
