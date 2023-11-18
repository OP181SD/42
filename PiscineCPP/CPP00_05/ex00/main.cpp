/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:11 by yassine           #+#    #+#             */
/*   Updated: 2023/11/18 17:15:07 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void displayHighGradeSection() {
    std::cout << "==== Bureaucrat avec une note haute ====\n";
    std::cout << "---------------------------------------------\n";
}

void displayLowGradeSection() {
    std::cout << "==== Bureaucrat avec une note basse ====\n";
    std::cout << "---------------------------------------------\n";
}

void Incrementation() {
    displayHighGradeSection();
    try {
        Bureaucrat Gwendoline("Gwendoline", 3);
        std::cout << Gwendoline << std::endl;
        Gwendoline.incrementelow(); 
        std::cout << "Après avoir incrémenté, Gwendoline a maintenant : " << Gwendoline << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    displayLowGradeSection();
    try {
        Bureaucrat Geraltine("Geraltine", 149);
        std::cout << Geraltine << std::endl;
        Geraltine.incrementehigh(); 
        std::cout << "Après avoir décrementé Geraltine a maintenant : " << Geraltine << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


int main() {
    Incrementation();
    return 0;
}
