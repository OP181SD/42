/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:19:56 by yassine           #+#    #+#             */
/*   Updated: 2024/02/16 12:55:43 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
    std::vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "If the element is found, its position is returned" << std::endl;
    try {
		
        std::vector<int>::iterator it = easyfind(vec, 9);
        std::cout << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "If the element is not found, an exception is thrown :"  << std::endl;
    try {
        easyfind(vec, 10); // Recherche de la valeur 10
    } catch(const NotFoundException& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}