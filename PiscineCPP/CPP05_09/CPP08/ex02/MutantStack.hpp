/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:49:02 by yasaidi           #+#    #+#             */
/*   Updated: 2024/01/28 13:25:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	MutantStack();
	MutantStack(MutantStack const &src);
	MutantStack &operator=(MutantStack const &rhs);
	~MutantStack();
	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
