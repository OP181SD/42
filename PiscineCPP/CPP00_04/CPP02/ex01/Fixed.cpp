/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:50:58 by yassine           #+#    #+#             */
/*   Updated: 2023/10/31 15:17:09 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :_value_fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) :_value_fixed(other._value_fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;   
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const constant_integer) :_value_fixed(constant_integer << num_bits_frac_part)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const constat_float) :_value_fixed(roundf(constat_float * (1 << num_bits_frac_part)))
{
     std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(_value_fixed) / static_cast<float>(1 << num_bits_frac_part));
}

int Fixed::toInt() const
{
    return (static_cast<int>(_value_fixed) / static_cast<int>(1 << num_bits_frac_part));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}
