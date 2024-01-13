/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 08:33:07 by yassine           #+#    #+#             */
/*   Updated: 2024/01/13 08:33:23 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
private:
	
public:
	Serializer();
	Serializer(Serializer const & src);
	Serializer & operator=(Serializer const & rhs);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};