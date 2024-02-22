/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:34:21 by yasaidi           #+#    #+#             */
/*   Updated: 2024/02/22 13:07:41 by yassine          ###   ########.fr       */
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

// Insertion sort
template<typename T>
void InsertionSort(T& container) 
{
    for (std::size_t i = 1; i < container.size(); ++i) 
	{
        typename T::value_type key = container[i];
        std::size_t j = i;
        while (j > 0 && container[j - 1] > key) 
		{
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

template<typename T>
void custom_swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

// Ford-Johnson sort
template<typename Iterator>
void FordJohnsonSort(Iterator begin, Iterator end) 
{
    int n = std::distance(begin, end);
    
    std::vector<typename std::iterator_traits<Iterator>::value_type> X(begin, end);
    
    for (int i = 0; i + 1 < n; i += 2) 
	{
    	typename std::iterator_traits<Iterator>::value_type& first = X[i];
    	typename std::iterator_traits<Iterator>::value_type& second = X[i + 1];
    	if (second < first)
        	custom_swap(first, second);
	}

    std::vector<typename std::iterator_traits<Iterator>::value_type> A_cont, B_cont;
    for (int i = 0; i < n; i++) 
	{
        if (i % 2 == 0) 
            B_cont.push_back(X[i]);
		else 
            A_cont.push_back(X[i]);
    }
	
    InsertionSort(A_cont);
    while (A_cont.size() != X.size()) 
	{
        A_cont.push_back(B_cont.back());
        B_cont.pop_back();
        InsertionSort(A_cont);
    }
	
	for (int i = 0; i < n; i++)
		*(begin + i) = X[i];
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
	FordJohnsonSort(vec.begin(), vec.end());
    clock_t end = clock();
    std::cout << "After: ";
    printContainer(vec);
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
      std::cout << "Time to process a range of " << vec.size() << " std::vector " << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
    std::deque<int> dq(vec.begin(), vec.end());
    start = clock();
	FordJohnsonSort(dq.begin(), dq.end());
    end = clock();
    elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << dq.size() << " std::deque " << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
    return 0;
}


