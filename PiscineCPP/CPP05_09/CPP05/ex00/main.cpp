/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:27:15 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/25 12:11:29 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Gwendoline("Gwendoline", 7);
		Gwendoline.Decrementevalue();
		std::cout << Gwendoline << std::endl;
		Gwendoline.Incrementevalue();
		std::cout << Gwendoline << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}