/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:28:36 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/23 11:58:20 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

T	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
	return (tmp);
}

template <typename T>

T	max(T &a, T &b)
{
	if (a > b)
	{
		return (a);
	}
	else
		return (b);
}

template <typename T>

T	min(T &a, T &b)
{
	if (a < b)
	{
		return (a);
	}
	else
		return (b);
}
