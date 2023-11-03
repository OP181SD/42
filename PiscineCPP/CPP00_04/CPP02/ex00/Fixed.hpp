/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:35:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/02 14:35:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
  private:
	int _value_fixed;
	int const static num_fractional_bits = 8;

  public:
	// Forme Canonique
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &rhs);
	// Getters
	int getRawBits(void) const;
	//Setters
	void setRawBits(int const raw);
};
