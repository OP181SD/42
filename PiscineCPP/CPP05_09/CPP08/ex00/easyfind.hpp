/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:18:28 by yassine           #+#    #+#             */
/*   Updated: 2024/01/26 12:39:12 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <list>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#include "easyfind.tpp"