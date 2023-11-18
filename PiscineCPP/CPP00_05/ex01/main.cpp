/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/18 17:51:56 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void Boss()
{
    Form id_0("Crocodile", 0, 1);
    std::cout << "---- Formulaire ----\n";
    std::cout << "Nom : " << id_0.GetName() << "\n"
              << "Grade requis : " << id_0.GetGrade() << "\n"
              << "Grade d'exécution : " << id_0.GetGradeExec() << "\n";	
}

int main(void)
{
	Boss();
    return (0);
}

