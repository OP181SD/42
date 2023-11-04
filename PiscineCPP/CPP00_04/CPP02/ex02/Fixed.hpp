/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:00:14 by yassine           #+#    #+#             */
/*   Updated: 2023/11/04 15:37:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	// Les 4 opérateurs de arithmétiques : +, -, *, et /.
	int operator+(const Fixed &other) const;
	int operator-(const Fixed &other) const;
	int operator*(const Fixed &other) const;
	int operator/(const Fixed &other) const;
	// Les 4 opérateurs d’incrémentation et de décrémentation
	Fixed  operator++(int);
	Fixed& operator++();
    Fixed  operator--(int);
    Fixed& operator--();
	// Getters
	int GetRawBits(void) const;
	// Setters
	void setRawBits(const int raw);

	// min max const
	static Fixed min(const Fixed &a, const Fixed &b);
	static Fixed max (const Fixed &a, const Fixed &b);
	// min max 
	static Fixed min (Fixed &a, Fixed &b);
	static Fixed max (Fixed &a, Fixed &b);

	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
private:
		int _value_fixed;
		int const static num_bits_frac_part = 8;
};

