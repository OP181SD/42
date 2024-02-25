/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:35:42 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/24 13:21:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: _vector()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
	: _vector(src._vector)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
		_vector = src._vector;
	return (*this);
}

void	MergeSortPairs(std::vector<std::pair<int, int> > &pairs)
{
	size_t	mid;

	if (pairs.size() <= 1)
		return ;
	mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
	MergeSortPairs(left);
	MergeSortPairs(right);
	std::inplace_merge(pairs.begin(), pairs.begin() + mid, pairs.end());
}

template <typename Container>
void	printContainer(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

size_t	binarySearch(const std::vector<int> &vec, int value)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	if (vec.empty())
		return (0);
	if (value < vec.front())
		return (0);
	left = 0;
	right = vec.size();
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (vec[mid] == value)
			return (mid);
		else if (value < vec[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return (left);
}

void PmergeMe::MergeInsertionSort()
{
	size_t size = _vector.size();
	size_t end_index = size - (size % 2);
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < end_index; i = i + 2)
		pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
		{
			int tmp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = tmp;
		}
	}
	MergeSortPairs(pairs);
	std::vector<int> S;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		S.push_back(pairs[i].first);
		S.push_back(pairs[i].second);
	}
	S.insert(S.begin(), _vector[size - 1]);
	std::vector<int> sorted;
	for (size_t i = 0; i < S.size(); i++)
	{
		size_t index = binarySearch(sorted, S[i]);
		if (index == sorted.size() || sorted[index] != S[i])
			sorted.insert(sorted.begin() + index, S[i]);
	}
	_vector = sorted;
}