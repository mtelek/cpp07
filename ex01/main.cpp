/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:49:20 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 14:55:34 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

// Test functions
template <typename T>
void printElement(T& element)
{
	std::cout << element << " ";
}

void increment(int& num)
{
	num++;
}

void capitalize(std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = toupper(str[i]);
}

void printDouble(const double& num)
{
	std::cout << num << " ";
}

int main()
{
	// Test with int array
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intL = sizeof(intArray) / sizeof(intArray[0]);
	
	std::cout << "Original int array: ";
	iter(intArray, intL, printElement<int>);
	std::cout << std::endl;
	
	iter(intArray, intL, increment);
	std::cout << "After increment: ";
	iter(intArray, intL, printElement<int>);
	std::cout << std::endl << std::endl;

	// Test with string array
	std::string strArray[] = {"hello", "world", "template", "functions"};
	size_t strL = sizeof(strArray) / sizeof(strArray[0]);
	
	std::cout << "Original string array: ";
	iter(strArray, strL, printElement<std::string>);
	std::cout << std::endl;
	
	iter(strArray, strL, capitalize);
	std::cout << "After capitalize: ";
	iter(strArray, strL, printElement<std::string>);
	std::cout << std::endl << std::endl;

	// Test with const double array (using const version of iter)
	const double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleL = sizeof(doubleArray) / sizeof(doubleArray[0]);
	
	std::cout << "Double array (const): ";
	iter(doubleArray, doubleL, printDouble);
	std::cout << std::endl;

	return (0);
}
