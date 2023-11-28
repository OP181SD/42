/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:20:32 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 11:31:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iomanip>
#include <iostream>

template <typename Type>

void iter(Type *tab, size_t lenght, void (*func) (Type& element))
{
	for (size_t i = 0; i < lenght; i++)
	{
		(func(tab[i]));
	}
}