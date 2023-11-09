/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:00:14 by yassine           #+#    #+#             */
/*   Updated: 2023/11/06 10:13:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

#pragma once 

class Fixed
{	
public:
	//Forme Canonique
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();
	// Constructeur de Copie
	Fixed(int const constant_interger);
	Fixed(float const constant_float);
	// Conversion
	float toFloat(void) const;
	int toInt(void) const;
	// Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);
	// Les 4 opérateurs de arithmétiques : +, -, *, et /.
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);
	// Les 4 opérateurs d’incrémentation et de décrémentation
	Fixed  operator++(int);
	Fixed& operator++();
    Fixed  operator--(int);
    Fixed& operator--();
	// Getters
	int getRawBits(void) const;
	// Setters
	void setRawBits(const int raw);
	// min max const
	static Fixed min(const Fixed &a, const Fixed &b);
	static Fixed max (const Fixed &a, const Fixed &b);
	// min max 
	static Fixed min (Fixed &a, Fixed &b);
	static Fixed max (Fixed &a, Fixed &b);
private:
		int _value_fixed;
		int const static num_bits_frac_part = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);