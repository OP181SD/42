/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seralizer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:44:34 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/18 20:23:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
  private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	~Serializer();

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
