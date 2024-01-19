/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:03 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/18 10:51:46 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seralizer.hpp"

int	main(void)
{
	Data *data = new Data;
	
	data->s1 = "hello";
	data->n = 42;

	std::cout << "Data: " << data->s1 << " " << data->n << std::endl;
	uintptr_t raw = Serializer::serialize(data);


	Data *data2 = Serializer::deserialize(raw);
	std::cout << "Data2: " << data2->s1 << " " << data2->n << std::endl;
	
	if (data->s1 == data2->s1 && data->n == data2->n)
		std::cout << "Data and Data2 are the same" << std::endl;
	else
		std::cout << "Data and Data2 are not the same" << std::endl;
		
	delete data;
	return (0);
}