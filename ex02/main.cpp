/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:58:11 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 16:45:54 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void testEmptyArray()
{
	std::cout << "\n=== TEST EMPTY ARRAY ===\n";
	Array<int> empty;
	std::cout << "Size: " << empty.size() << " (expected: 0)\n";
	
	try
	{
		std::cout << "Attempting to access empty array: ";
		empty[0] = 5;
		std::cout << "FAILED - No exception thrown!\n";
	} catch (const std::out_of_range& e)
	{
		std::cout << "PASSED - Exception: " << e.what() << "\n";
	}
}

void testIntArray()
{
	std::cout << "\n=== TEST INT ARRAY ===\n";
	Array<int> numbers(5);
	std::cout << "Size: " << numbers.size() << " (expected: 5)\n";
	
	// Test initialization
	std::cout << "Default values: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "(expected: 0 0 0 0 0)\n";
	
	// Test assignment
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;
	
	std::cout << "Modified values: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "(expected: 0 10 20 30 40)\n";
	
	// Test bounds checking
	try
	{
		std::cout << "Attempting numbers[10]: ";
		numbers[10] = 100;
		std::cout << "FAILED - No exception thrown!\n";
	} catch (const std::out_of_range& e) 
	{
		std::cout << "PASSED - Exception: " << e.what() << "\n";
	}
}

void testStringArray()
{
	std::cout << "\n=== TEST STRING ARRAY ===\n";
	Array<std::string> words(3);
	
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "!";
	
	std::cout << "Strings: ";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "(expected: Hello World !)\n";
	
	// Test const access
	const Array<std::string> const_words(words);
	std::cout << "Const access: " << const_words[0] 
			  << " (expected: Hello)\n";
}

void testCopyAndAssignment()
{
	std::cout << "\n=== TEST COPY AND ASSIGNMENT ===\n";
	Array<int> original(3);
	original[0] = 1;
	original[1] = 2;
	original[2] = 3;
	
	// Test copy constructor
	Array<int> copy(original);
	copy[0] = 100;
	
	std::cout << "Original[0]: " << original[0] << " (expected: 1)\n";
	std::cout << "Copy[0]: " << copy[0] << " (expected: 100)\n";
	
	// Test assignment operator
	Array<int> assigned;
	assigned = original;
	assigned[1] = 200;
	
	std::cout << "Original[1]: " << original[1] << " (expected: 2)\n";
	std::cout << "Assigned[1]: " << assigned[1] << " (expected: 200)\n";
}

void testEdgeCases()
{
	std::cout << "\n=== TEST EDGE CASES ===\n";
	// Test size 1 array
	Array<char> single(1);
	single[0] = 'A';
	std::cout << "Single element: " << single[0] << " (expected: A)\n";
	
	// Test very large array
	Array<int> large(1000000);
	std::cout << "Large array created (size: " << large.size() << ")\n";
}

int main()
{
	testEmptyArray();
	testIntArray();
	testStringArray();
	testCopyAndAssignment();
	testEdgeCases();
	
	std::cout << "\nAll tests completed!\n";
	return (0);
}
