/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:39:26 by yassine           #+#    #+#             */
/*   Updated: 2023/10/31 15:18:03 by yassine          ###   ########.fr       */
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
    Fixed();
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed& rhs);
    ~Fixed();
    // Constructeur de Copie
    Fixed(int const constant_interger);
    Fixed(float const constant_float);
    // Conversion
    float toFloat( void ) const;
    int toInt( void ) const;
    // Surcharge d'operateur
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};