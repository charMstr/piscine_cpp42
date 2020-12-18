/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 08:03:45 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 10:00:10 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Dummy.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON SWAP *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"swaping ints \033[m" \
		<< std::endl;
	{
		int j = 88;
		int i = 77;
		std::cout << "BEFORE SWAP: " << "j = " << j << ", i = " << i << std::endl;
		swap<int>(j, i);
		std::cout << "AFTER SWAP:  " << "j = " << j << ", i = " << i << std::endl;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"swaping char \033[m" \
		<< std::endl;
	{
		char j = 'B';
		char i = 'A';
		std::cout << "BEFORE SWAP: " << "j = " << j << ", i = " << i << std::endl;
		swap<char>(j, i);
		std::cout << "AFTER SWAP:  " << "j = " << j << ", i = " << i << std::endl;
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"swaping pointers to int \033[m" \
		<< std::endl;
	{
		int j = 88;
		int i = 42;
		int *ptr_j = &j;
		int *ptr_i = &i;
		std::cout << "BEFORE SWAP: " << "j = " << *ptr_j << ", i = " << *ptr_i \
			<< std::endl;
		swap<int*>(ptr_j, ptr_i);
		std::cout << "AFTER SWAP:  " << "j = " << *ptr_j << ", i = " << *ptr_i \
			<< std::endl;
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"swaping pointers to int with a pointer to null\033[m" \
		<< std::endl;
	{
		int j = 88;
		int *ptr_j = &j;
		int *ptr_i = NULL;
		std::cout << "BEFORE SWAP: " << "ptr_j = " << ptr_j << ", ptr_i = " << \
			ptr_i  << std::endl;
		swap<int*>(ptr_j, ptr_i);
		std::cout << "AFTER SWAP:  " << "ptr_j = " << ptr_j << ", ptr_i = " << \
			ptr_i  << std::endl;
	}



	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON MIN *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"min with ints \033[m" \
		<< std::endl;
	{
		int j = 88;
		int i = 77;
		std::cout << "BEFORE MIN: " << "j = " << j << ", i = " << i << std::endl;
		int res = min<int>(j, i);
		std::cout << "RES MIN:  " << res << std::endl;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"min char \033[m" \
		<< std::endl;
	{
		char j = 'B';
		char i = 'A';
		std::cout << "BEFORE MIN: " << "j = " << j << ", i = " << i << std::endl;
		char res = min<char>(j, i);
		std::cout << "RES MIN:  " << res << std::endl;
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"min pointers to int \033[m" \
		<< std::endl;
	{
		int j = 88;
		int *ptr_j = &j;
		int *ptr_i = NULL;
		std::cout << "BEFORE MIN: " << "ptr_j = " << ptr_j << ", ptr_i = " << \
			ptr_i  << std::endl;
		int *res = min<int*>(ptr_j, ptr_i);
		std::cout << "RES MIN:  " << res << std::endl;
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"my own class \033[m" \
		<< std::endl;
	{
		Dummy i(42);
		Dummy j(88);
		std::cout << "BEFORE MIN: " << std::endl;
		std::cout << "i (class Dummy): " << i;
		std::cout << "j (class Dummy): " << j;
		Dummy res  = min<Dummy>(j, i);
		std::cout << "AFTER MIN:" << std::endl;
		std::cout << "res (class Dummy): " << res;
		std::cout << std::endl;
		std::cout << "BEFORE MAX: " << std::endl;
		std::cout << "i (class Dummy): " << i;
		std::cout << "j (class Dummy): " << j;
		res = max<Dummy>(j, i);
		std::cout << "AFTER MAX:" << std::endl;
		std::cout << "res (class Dummy): " << res;
	}
	return (0);
}
