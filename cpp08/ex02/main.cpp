/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:07:23 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 00:08:17 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"MutantStack.hpp"
#include <iostream>


int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{

	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON MUTANT STACK  *******" << std::endl;

	MutantStack<int> my_stack;
	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(3);
	my_stack.push(4);

	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"iterating from begining to end \033[m" \
		<< std::endl;
	{
		std::cout << "stack contains:" << std::endl;
		for (MutantStack<int>::iterator it = my_stack.begin(); it != my_stack.end(); it++)
			std::cout << *it << std::endl;
	}

	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"iterating from end to begining \033[m" \
		<< std::endl;
	{
		std::cout << "stack contains:" << std::endl;
		MutantStack<int>::iterator it = my_stack.end();
		while (1)
		{
			it--;
			std::cout << *it  << std::endl;
			if (it == my_stack.begin())
				break;
		}
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"reverse iterating from begining \033[m" \
		<< std::endl;
	{
		std::cout << "stack contains:" << std::endl;
		MutantStack<int>::reverse_iterator it = my_stack.rbegin();
		while (1)
		{
			std::cout << *it  << std::endl;
			++it;
			if (it == my_stack.rend())
				break;
		}
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"reverse iterating from end \033[m" \
		<< std::endl;
	{
		std::cout << "stack contains:" << std::endl;
		MutantStack<int>::reverse_iterator it = my_stack.rend();
		while (1)
		{
			it--;
			std::cout << *it  << std::endl;
			if (it == my_stack.rbegin())
				break;
		}
	}

	std::cout << std::endl << "\033[35m************************* SUBJECT TESTS" \
		" ON MUTANT STACK  *******\033[m" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
