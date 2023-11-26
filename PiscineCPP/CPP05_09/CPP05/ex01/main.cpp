/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:27:15 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/26 09:10:34 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat Chloé("Chloé", 24);
    Form Form1("Form1", 24, 24); 
    Form Form2("Form2", 12, 13); 

    try {
        std::cout << "Trying to create Form3...\n";
        Form Form3("Form3", 0, 151); 
    }
    catch (const std::exception& e) {
        std::cout << "Couldn't create Form3: " << e.what() << std::endl;
    }

    std::cout << "\nSigning Form1...\n";
    Chloé.signForm(Form1); 
    std::cout << "Signing Form2...\n";
    Chloé.signForm(Form2);
    return 0;
}
