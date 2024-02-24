/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:49:02 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/21 10:32:37 by yasaidi          ###   ########.fr       */
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
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

#include "MutantStack.tpp"
