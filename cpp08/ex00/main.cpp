/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:17:40 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/20 13:28:13 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include "easyfind.hpp"
#include <iostream>

class print
{
	public:
	void operator()(int a)
	{
		std::cout << a << std::endl;
	}
};

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON EASYFIND *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"container type = std::vector<int> \033[m" \
		<< std::endl;
	{
		std::vector<int> vec(4,0); //vector of 3 indexes. all initiated to 1

		vec[2] = 42;
		std::cout << "displaying all the elements in the vector: " << std::endl;
		std::for_each(vec.begin(), vec.end(), print());
		std::cout << std::endl;

		std::vector<int>::iterator it;
		std::cout << "looking for 42:" << std::endl;
		it = easyfind<std::vector<int> >(vec, 42);
		if (it != vec.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 42" << std::endl;
		std::cout << "looking for 41:" << std::endl;
		it = easyfind<std::vector<int> >(vec, 41);
		if (it != vec.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 41" << std::endl;
	}
	
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"container type = std::map<int> \033[m" \
		<< std::endl;
	{
		std::set<int> my_set; //set of 3 indexes. all initiated to 1

		my_set.insert(1);
		my_set.insert(12);
		my_set.insert(42);
		my_set.insert(66);
		std::cout << "displaying all the elements in the set: " << std::endl;
		std::for_each(my_set.begin(), my_set.end(), print());
		std::cout << std::endl;

		std::set<int>::iterator it;
		std::cout << "looking for 42:" << std::endl;
		it = easyfind<std::set<int> >(my_set, 42);
		if (it != my_set.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 42" << std::endl;
		it = easyfind<std::set<int> >(my_set, 41);
		std::cout << "looking for 41:" << std::endl;
		if (it != my_set.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 41" << std::endl;
	}

	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"container type = std::map<int> \033[m" \
		<< std::endl;
	{
		std::list<int> my_list; //set of 3 indexes. all initiated to 1

		my_list.push_back(1);
		my_list.push_back(12);
		my_list.push_back(42);
		my_list.push_back(66);
		std::cout << "displaying all the elements in the list: " << std::endl;
		std::for_each(my_list.begin(), my_list.end(), print());
		std::cout << std::endl;

		std::list<int>::iterator it;
		std::cout << "looking for 42:" << std::endl;
		it = easyfind<std::list<int> >(my_list, 42);
		if (it != my_list.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 42" << std::endl;
		it = easyfind<std::list<int> >(my_list, 41);
		std::cout << "looking for 41:" << std::endl;
		if (it != my_list.end())
			std::cout << *it << std::endl;
		else
			std::cout << "could not find 41" << std::endl;
	}

	//trying with std::string : does not compile! -->  OK
	/*
	std::vector<std::string> vec2(3, 0);
	vec2[0] = "salut";
	vec2[1] = "peer";
	vec2[2] = "from 42";
	std::vector<std::string> it2;
	it2 = easyfind(vec2, 3);
	*/
	return (0);
}
