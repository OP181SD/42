/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:34 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/24 12:28:36 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <sys/time.h>

class PmergeMe
{
  private:
	std::vector<int> _vector;
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	int	Conversion(int argc, char *argv[]);
	std::vector<int> getVector();
	void MergeInsertionSort();
	~PmergeMe();
};
