/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:33 by yassine           #+#    #+#             */
/*   Updated: 2023/10/04 12:58:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string *stringPTR;
	std::string str = "HI THIS IS BRAIN";
	std::string &stringREF = str;
	stringPTR = &str;
	std::cout << "Adresse de la string : " << &str << std::endl;
	std::cout << "Adresse stockée dans stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse stockée dans stringREF : " << &stringREF << std::endl;
	std::cout << "Valeur de la string : " << str << std::endl;
	std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF : " << stringREF << std::endl;
	return (0);
}
