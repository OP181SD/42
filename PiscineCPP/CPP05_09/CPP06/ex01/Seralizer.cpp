/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seralizer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:PiscineCPP/CPP05_09/CPP06/ex01/Seralizer.cpp
/*   Created: 2024/01/13 08:33:39 by yassine           #+#    #+#             */
/*   Updated: 2024/01/13 08:33:50 by yassine          ###   ########.fr       */
=======
/*   Created: 2023/11/28 11:43:01 by yassine           #+#    #+#             */
/*   Updated: 2023/11/29 09:38:27 by yassine          ###   ########.fr       */
>>>>>>> 8094b989d92e19c2282450973ddb8f0438e3d2b4:PiscineCPP/CPP05_09/CPP06/ex01/Serializer.cpp
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const & src)
{
	*this = src;
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
	(void)rhs;
	return *this;
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}