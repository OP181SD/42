/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:00:18 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 10:13:55 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename Type>

void swap(Type &a, Type &b)
{
	Type tmp = a;
	a = b;
	b = tmp;	
}

template <typename Type>

Type& min(Type &a, Type &b)
{
	if (a < b)
		return (a);
	else
		return (b);	
}

template <typename Type>

Type& max(Type &a, Type &b)
{
	if (a > b)
		return (a);
	else
		return (b);	
}
