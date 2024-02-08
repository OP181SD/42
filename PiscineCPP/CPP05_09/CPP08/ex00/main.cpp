/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:19:56 by yassine           #+#    #+#             */
/*   Updated: 2024/01/28 13:16:43 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	
    std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		std::cout << vec[i] << " "; 
	}
	std::cout << std::endl;
	std::cout << "If the element is found, its position is returned" << std::endl;
    try {
       std::vector<int>::iterator it =   easyfind(vec,1);	
	   std::vector<int>::iterator it_1 = easyfind(vec,5);
	   std::vector<int>::iterator it_2 = easyfind(vec,9);
	   std::vector<int>::iterator it_3 = easyfind(vec,0);
	   
	   std::cout << *it << std::endl;
	   std::cout << *it_1 << std::endl;
	   std::cout << *it_2 << std::endl;
	   std::cout << *it_3 << std::endl;
	   
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "If the element is not found, an exception is thrown :"  << std::endl;
	
	try
	{
		easyfind(vec, 10);
	}
	catch(const NotFoundException& e)
	{
		std::cerr << e.what() << '\n';
	}
    return 0;
}