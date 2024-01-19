/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seralizer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:49:24 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/17 10:26:38 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seralizer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}