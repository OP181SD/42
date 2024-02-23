/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:34 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/23 10:34:50 by yassine          ###   ########.fr       */
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
	void	Conversion(int argc, char *argv[]);
	void MergeInsertionSort();
	~PmergeMe();
};
