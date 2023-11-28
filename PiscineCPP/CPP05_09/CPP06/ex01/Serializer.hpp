/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:53 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 20:46:31 by yassine          ###   ########.fr       */
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