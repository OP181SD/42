/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:53:05 by yassine           #+#    #+#             */
/*   Updated: 2024/01/26 12:39:04 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFoundException::what() const throw()
{
	return ("Element not found in container");
}

template <typename T>
typename T::iterator easyfind(T& container, int a)
{
	typename T::iterator it;
	it = std::find(container.begin(),container.end(),a);
	if (it == container.end())
		throw NotFoundException();
	else
		return (it);
}