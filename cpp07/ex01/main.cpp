/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:46:07 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 11:43:51 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	upperCase(char &c)
{
	if (c >= 'a' && c<= 'z')
		c -= 'a' - 'A';
}

//delete the last character of a non empty string.
void shortenString(std::string &str)
{
	if (str.length() > 0)
		str.erase(str.length() - 1);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{	
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON ITER *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"upperCase on char *\033[m" \
		<< std::endl;
	{
		char array1[13] = "hello world";
		char array2[13] = "hello world";

		std::cout << "JUST USING THE FUNCTION:" << std::endl;
		std::cout << "	BEFORE: array1 = \"" << array1 << "\"" << std::endl;
		for (int i = 0; i < 12; i++)
		{
			upperCase(array1[i]);
		}
		std::cout << "	AFTER:x array1 = \"" << array1 << "\"" << std::endl;

		std::cout << "" << std::endl;

		std::cout << "WITH MY ITER TEMPLATE:" << std::endl;
		std::cout << "	BEFORE: array2 = \"" << array2 << "\"" << std::endl;
		iter<char>(array2, 12, upperCase);
		std::cout << "	AFTER:  array2 = \"" << array2 << "\"" << std::endl;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"3rd param is an instanciated function template \033[m" \
		<< std::endl;

	{
		char array1[13] = "hello world";

		std::cout << "	BEFORE: array1 = \"" << array1 << "\"" << std::endl;
		iter<char>(array1, 12, funcIter<char>);
		std::cout << "	AFTER:  array2 = \"" << array1 << "\"" << std::endl;
	}
	//TEST 3) 
	std::cout << std::endl << "\033[35mTEST 3) "
		"removing the last char from a strings array. \033[m" \
		<< std::endl;

	{
		std::string strings_array[3];
		strings_array[0] = "hi guys how are you doing today?";
		strings_array[1] = "hope you are having fun correcting me";
		strings_array[2] = "HELLO";
		//std::string str = "hello world";

		std::cout << "	BEFORE: strings_array:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << strings_array[i]  << std::endl;
		iter<std::string>(strings_array, 3, shortenString);
		std::cout << "	AFTER:  strings_array:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << strings_array[i]  << std::endl;
		//std::cout << "	AFTER:x array2 = \"" << str << "\"" << std::endl;
	}
	//TEST 4) 
	std::cout << std::endl << "\033[35mTEST 4) "
		"applying if != 42 -> = 0 on int array. \033[m" \
		<< std::endl;
	{
		int array_int[] =
		{
			1, 3, 42, 12, 43, 42, 41, 66, 10
		};
		int size = sizeof(array_int)/sizeof(array_int[0]);
		std::cout << "	BEFORE: array_int contains" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << array_int[i]; 
			if (i < (size - 1))
				std::cout << ", ";
			else
				std::cout << std::endl;
		}
		iter<int>(array_int, size, funcIter2<int>);
		std::cout << "	AFTER:  array_int contains" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << array_int[i]; 
			if (i < (size - 1))
				std::cout << ", ";
			else
				std::cout << std::endl;
		}
	}
	return (0);
}
