/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:21:27 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 11:31:14 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void processInt(int& element)
{
    element *= 2;
}

void processDouble(double& element)
{
    element *= 2.0;
}
void processString(std::string& element)
{
    element = "Traitée : " + element;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"Bonjour", "Monde", "C++", "Modèles"};

    std::cout << "Tableau d'entiers : ";
    iter(intArray, 5, processInt);
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Tableau de Doubles : ";
    iter(doubleArray, 5, processDouble);
    for (int i = 0; i < 5; i++)
    {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Tableau de Chaînes de Caractères :" << std::endl;
    iter(stringArray, 4, processString);
    for (int i = 0; i < 4; i++)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

