/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:08:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 15:46:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <exception>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON ARRAY *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"instanciating an empty array\033[m" \
		<< std::endl;
	{
		Array<int> arr1;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"instanciating an array of 1, trying to access out of range\033[m" \
		<< std::endl;
	{
		Array<int> arr1(1);
		for (size_t i = 0; i < 3; i++)
		{
			try
			{
				std::cout << arr1[i] << std::endl;
			}
			catch (const std::out_of_range& oor)
			{
				std::cout << oor.what() << std::endl;
			}
		}
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"instanciating an array of 3, another by copy, and then the = operator\033[m" \
		<< std::endl;
	{
		Array<int> arr1(3);
		arr1[0] = 42;
		arr1[1] = 12;
		arr1[2] = 8;

		Array<int> arr2(arr1);
		Array<int> arr3;
		arr3 = arr1;
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << arr1[i] <<" == "<< arr2[i] <<" == "<< arr3[i] << std::endl;
		}
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"array of size 18, geting its size\033[m" \
		<< std::endl;
	{
		Array<int> arr1(18);
		std::cout << arr1.size()  << std::endl;
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"array of arrays of characters\033[m" \
		<< std::endl;
	{
		Array<char> arr1(3);
		arr1[0] = 'a';
		arr1[1] = 'b';
		arr1[2] = 'c';
		Array<char> arr2(3);
		arr2[0] = 'x';
		arr2[1] = 'y';
		arr2[2] = 'x';
		//array of arrays
		Array< Array< char > > array_of_arrays(2);
		array_of_arrays[0] = arr1;
		array_of_arrays[1] = arr2;
		for (int i = 0; i < 2 ; i++)
		{
			std::cout << "ARRAY: "  << i << std::endl;
			for (int j = 0; j < 3; j++)
			{
				std::cout << array_of_arrays[i][j];
				if (j < 3 - 1)
					std::cout << ", ";
				else
					std::cout  << std::endl;
			}
		}
	}
	return (0);
}
