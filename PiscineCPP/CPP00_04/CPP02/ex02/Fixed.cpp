/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:00:02 by yassine           #+#    #+#             */
/*   Updated: 2023/11/05 11:00:27 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value_fixed(0) {}

Fixed::Fixed(int const constant_interger) 
: _value_fixed(constant_interger << num_bits_frac_part) {}

Fixed::Fixed(float const constant_float) 
: _value_fixed(int(roundf(constant_float * (1 << num_bits_frac_part)))) {}

Fixed::Fixed(const Fixed& other) : _value_fixed(other._value_fixed) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		_value_fixed = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &other) 
{
	return (this->_value_fixed > other._value_fixed);
}

bool Fixed::operator<(const Fixed &other)
{
	return (this->_value_fixed < other._value_fixed);
}

bool Fixed::operator>=(const Fixed &other)
{
	return (this->_value_fixed >= other._value_fixed);
}

bool Fixed::operator<=(const Fixed &other)
{
	return (this->_value_fixed <= other._value_fixed);
}

bool Fixed::operator==(const Fixed &other)
{
	return (this->_value_fixed == other._value_fixed);
}

bool Fixed::operator!=(const Fixed &other) 
{
	return (this->_value_fixed != other._value_fixed);
}

Fixed Fixed::operator+(const Fixed& other)
{
   Fixed result;

   result._value_fixed = this->_value_fixed + other._value_fixed;
    return (result);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed result;

    result._value_fixed = this->_value_fixed - other._value_fixed;
    return (result);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed result;

    result._value_fixed = this->_value_fixed * (other._value_fixed >> num_bits_frac_part);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed result;

    result._value_fixed = this->_value_fixed / (other._value_fixed >> num_bits_frac_part);
    return (result);
}  

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	_value_fixed++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_value_fixed--;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_value_fixed);
}

void Fixed::setRawBits(const int raw) 
{
	this->_value_fixed = raw;
}

float Fixed::toFloat() const 
{
    return static_cast<float>(_value_fixed) / (1 << num_bits_frac_part);
}

int Fixed::toInt() const
{
	return (_value_fixed >> num_bits_frac_part);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a._value_fixed < b._value_fixed) {
        return a;
    } else {
        return b;
    }
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a._value_fixed > b._value_fixed) {
        return a;
    } else {
        return b;
    }
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}