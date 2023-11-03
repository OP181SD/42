/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:25 by yasaidi           #+#    #+#             */
/*   Updated: 2023/11/02 14:25:41 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

class Fixed
{
  private:
	int _value_fixed;
	int const static num_bits_frac_part = 8;

  public:
	// Forme Canonique
	// Constructeur par défaut
	Fixed();
	// Constructeur de copie
	Fixed(const Fixed &other);
	// Opérateur d'affectation
	Fixed &operator=(const Fixed &rhs);
	// Destructeur
	~Fixed();
	// Les 6 opérateurs de comparaison : >, <, >=, <=, == et !=
	bool operator>(const Fixed &higer) const;
	bool operator<(const Fixed &lower) const;
	bool operator>=(const Fixed &higerorequal) const;
	bool operator<=(const Fixed &lowerorequal) const;
	bool operator==(const Fixed &equal) const;
	bool operator!=(const Fixed &diff) const;
	// Les 4 opérateurs d'arithmétiques : +, -, *, et /
	Fixed operator+(const Fixed &plus) const;
	Fixed operator-(const Fixed &minus) const;
	Fixed operator*(const Fixed &mult) const;
	Fixed operator/(const Fixed &div) const;
	// Les 4 opérateurs d'incrémentation et de décrémentation : ++ --
	// Surcharge d'opérateur
	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};
