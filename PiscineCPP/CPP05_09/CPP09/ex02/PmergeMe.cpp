/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:35:42 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/24 11:18:53 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector()
{
}

PmergeMe::PmergeMe(const PmergeMe &src) : _vector(src._vector)
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


void MergeSortPairs(std::vector<std::pair<int, int> >& pairs) 
{
    // Base case: if the number of pairs is less than or equal to 1, no need to sort
    if (pairs.size() <= 1) {
        return;
    }

    // Split the vector of pairs into two halves
    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
	
    // Recursively sort the left and right halves
    MergeSortPairs(left);
    MergeSortPairs(right);
    // Merge the sorted halves using std::inplace_merge
    std::inplace_merge(pairs.begin(), pairs.begin() + mid, pairs.end());
}

template <typename Container>
void printContainer(const Container& container) 
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


size_t binarySearch(const std::vector<int>& vec, int value) {
    // Si vec est vide, retourne 0
    if (vec.empty())
        return 0;

    // Si la valeur est inférieure au premier élément, retourne 0
    if (value < vec.front())
        return 0;
    size_t left = 0;
    size_t right = vec.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (vec[mid] == value)
            return mid;
        else if (value < vec[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

void PmergeMe::MergeInsertionSort()
{
	 size_t size = _vector.size();
    size_t end_index = size - (size % 2); 
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i < end_index; i = i + 2)
        pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
    if (size % 2 != 0)
	{
		std::cout << "Unpaired element: [" << _vector[size - 1] << "]" << std::endl;
	}
	// std::cout << "Sort each pair: " << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
		{
			int tmp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = tmp;
		}
		// std::cout << "Pair " << i << ": [" << pairs[i].first << ", " << pairs[i].second << "]" << std::endl;
	}
	MergeSortPairs(pairs);
	std::vector<int> S;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		S.push_back(pairs[i].first);
		S.push_back(pairs[i].second);
	}
	// std::cout << "Merge the sorted pairs: " << std::endl;
	// printContainer(S);
	S.insert(S.begin(), _vector[size - 1]);
	// std::cout << "Sort the merged array: " << std::endl;
	std::vector<int> sorted;
	for (size_t i = 0; i < S.size(); i++) 
	{
    size_t index = binarySearch(sorted, S[i]);
    if (index == sorted.size() || sorted[index] != S[i])
        sorted.insert(sorted.begin() + index, S[i]);
	}
	_vector = sorted;
}