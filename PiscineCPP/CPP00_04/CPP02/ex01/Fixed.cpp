/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:50:58 by yassine           #+#    #+#             */
/*   Updated: 2023/11/05 10:11:57 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _value_fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
	: _value_fixed(other._value_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_value_fixed= rhs._value_fixed;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const constant_integer)
	: _value_fixed(constant_integer << num_bits_frac_part)
{ 
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const constat_float)
	: _value_fixed(roundf(constat_float * (1 << num_bits_frac_part)))
{
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_value_fixed);
}

float Fixed::toFloat() const
{
	return ((float)(_value_fixed) / (1 << num_bits_frac_part));
}

int Fixed::toInt() const
{
        return (_value_fixed >> num_bits_frac_part);
}

void Fixed::setRawBits(const int raw)
{
	this->_value_fixed = raw;
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
