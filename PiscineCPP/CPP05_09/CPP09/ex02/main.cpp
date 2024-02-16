/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:21 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/16 11:23:48 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int	only_digits(std::string s1)
{
	for (size_t j = 0; j < s1.size(); ++j)
	{
		if (!std::isdigit(s1[j]))
		{
			std::cerr << "Error: Invalid input char detected " << std::endl;
			return (1);
		}
	}
	return (0);
}

int	is_duplicate(std::string s1, int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		for (int j = i + 1; j < argc; ++j)
		{
			if (s1 == argv[j])
			{
				std::cerr << "Error: Duplicate input" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int	out_of_range(std::string s1)
{
	long	string_to_long;

	string_to_long = std::atol(s1.c_str());
	if (string_to_long > std::numeric_limits<int>::max()
		|| string_to_long < std::numeric_limits<int>::min())
	{
		std::cerr << "Error: Out of range" << std::endl;
		return (1);
	}
	return (0);
}

int	Parsing(std::string s1)
{
	if (only_digits(s1) || out_of_range(s1))
		return (1);
	return (0);
}

int	Input(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string s1 = argv[i];
		if (Parsing(s1))
			return (1);
	}
	return (0);
}

template <typename Container>
void printContainer(const Container& container) 
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


void	Conversion(int argc, char *argv[], std::vector<int> &vector)
{
	long	string_to_long;

	std::string s1;
	for (int i = 1; i < argc; ++i)
	{
		s1 = argv[i];
		string_to_long = std::atol(s1.c_str());
		vector.push_back(string_to_long);
		vector[i - 1] = vector.back();

	}
}

template<typename T>
void insertionSort(T begin, T end) 
{
    for (T i = begin + 1; i != end; ++i) 
	{
        typename T::value_type key = *i;
        T j = i;
        while (j != begin && *(j - 1) > key) 
		{
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

template<typename Iterator>
void MergeInsertSort(Iterator begin, Iterator end) 
{
    if (std::distance(begin, end) <= 1)
        return;
    if (std::distance(begin, end) < 16) 
	{
        insertionSort(begin, end);
        return;
    }
    Iterator middle = begin + std::distance(begin, end) / 2;
    MergeInsertSort(begin, middle);
    MergeInsertSort(middle, end);
    std::inplace_merge(begin, middle, end);
}

int main(int argc, char *argv[]) 
{
    if (Input(argc, argv))
        return 1;

    std::vector<int> vec;
    Conversion(argc, argv, vec);
    std::cout << "Before: ";
    printContainer(vec);
    clock_t start = clock();
	MergeInsertSort(vec.begin(), vec.end());
    clock_t end = clock();
    std::cout << "After: ";
    printContainer(vec);
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << vec.size() << " std::vector " << elapsed_time << " us" << std::endl;
    std::deque<int> dq(vec.begin(), vec.end());
    start = clock();
	MergeInsertSort(dq.begin(), dq.end());
    end = clock();
    elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << dq.size() << " std::deqeu " << elapsed_time << " us" << std::endl;

    return 0;
}