/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:23:15 by yassine           #+#    #+#             */
/*   Updated: 2024/02/17 18:29:39 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char * Span::SpanException::what() const throw()
{
	return ("Attempted to add a number to a full Span.");
}

const char * Span::NoEnoughValue::what() const throw()
{
	return ("Not enough numbers to calculate the span.");
}

void Span::SpanPrint()
{
	std::cout << _AQUAMARINE;
	std::cout << "Element Of the Span \n";
	std::cout << _CYAN;
	for (size_t i = 0; i < _v.size(); i++)
	{
		std::cout << "[" <<  _v[i] << "]";
	}	

	std::cout << RESET_COLOR;

	std::cout << "\n";
}

void Span::SpanPrintSort()
{
	std::cout << _FOREST_GREEN;
	std::cout << "Element Of the Span Sorted \n";
	std::cout << _LAGOON;
	for (size_t i = 0; i < _v.size(); i++)
	{
		std::cout << "[" <<  _v[i] << "]";
	}	
	std::cout << RESET_COLOR;

	std::cout << "\n";
}

// Test Functions
void testSpanWithLessThanTwoNumbers() {
    std::cout << _RED << "Trying to calculate the shortest span when there are less than 2 numbers..." << _END << std::endl;
    try {
        Span sp(4);
        sp.shortestSpan();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void testWhenSpanIsFull() {
    std::cout << _PURPLE << "Trying to add a number when the Span is full..." << _END << std::endl;
    try {
        Span sp(4);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
        sp.shortestSpan();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

// Shortest Span
void testShortestSpan() {
    std::cout << _LILAC << "Calculating shortest span..." << _END << std::endl;
    try {
		Span sp(5);
        sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
        sp.shortestSpan();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

// Longest Span
void testLongestSpan() {
	std::cout << _SALMON << "Calculating longest span..." << _END << std::endl;
	try {
		Span sp(5);
        sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.longestSpan();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}


void runHardMode(void)
{
    Span sp(100);
    srand(time(NULL));
    for (int i = 0; i < 100; ++i)
    {
        sp.addNumber(rand() % 100);
    }
    try
    {
        char choice;
      	std::cout << _RED << _BOLD << _ITALIC << _UNDERLINE << _BLINK << "Warning: Are you sure you want to run HardMode? (s) for ShortestSpan or (l) for LongestSpan :" << _END << std::endl;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 's')
        {
            std::cout << "Shortest span: " << std::endl;
            sp.shortestSpan();
        }
        else if (choice == 'l')
        {
            std::cout << "Longest span: " << std::endl;
            sp.longestSpan();
        }
        else
        {
            std::cout << "Invalid input. Please enter 's' for ShortestSpan or 'l' for LongestSpan." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
       	std::cout << _RED << _BOLD << _ITALIC << "Usage: ./Span [Type Something...]" << _END << std::endl;
        return 1;
    }
    std::cout << _YELLOW << _BOLD << "Welcome to - Span" << _END << std::endl;
    std::cout << _CYAN << "====================" << _END << std::endl;
   std::cout << _YELLOW << "Please Type : " << _END << _BOLD << _UNDERLINE << _CYAN << "ShortestSpan" << _END << ", " << _BOLD << _UNDERLINE << _MAGENTA << "LongestSpan" << _END << ", " << _BOLD << _UNDERLINE << _RED << "HardMode" << _END << std::endl;
    std::cout << _CYAN << "====================" << _END << std::endl;
    if (argc == 2)
    {
        std::string ST = argv[1];
        if (ST == "ShortestSpan")
        {
            testSpanWithLessThanTwoNumbers();
			testWhenSpanIsFull();
            testShortestSpan();
        }
		else if (ST == "LongestSpan")
		{
			testSpanWithLessThanTwoNumbers();
			testWhenSpanIsFull();
			testLongestSpan();
		}
		else if (ST == "HardMode")
		{
			runHardMode();
		}
    }
    return 0;
}