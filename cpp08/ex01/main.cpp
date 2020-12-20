/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 13:32:17 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/20 18:43:32 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <exception>
#include "iostream"
#include <stdlib.h> // srand and rand
#include <time.h> //initializing time

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON EASYFIND *******" << std::endl;
	
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"Span initiated to 4, trying to add a fifth int\033[m" \
		<< std::endl;
	{
		Span my_span(4);

		for (int i = 0; i < 4 ; i++)
		{
			my_span.addNumber(i);	
		}
		try
		{
			my_span.addNumber(42);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what()  << std::endl;
		}
	}

	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"Span initiated to 1 element, try to get longestspan\033[m" \
		<< std::endl;
	{
		Span my_span(1);

		my_span.addNumber(42);
		try
		{
			int span = my_span.longestSpan();
			std::cout << "longest spas is: " << span << std::endl;
		}
		catch (std::exception const &e){ std::cout << e.what()  << std::endl; }
	}

	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"Span initiated to 4 elements, getting longestSpan\033[m" \
		<< std::endl;
	{
		Span my_span(4);

		my_span.addNumber(12);
		my_span.addNumber(1);
		my_span.addNumber(43);
		my_span.addNumber(13);
		int longest_span = my_span.longestSpan();
		std::cout << "longestSpan output: " << longest_span  << std::endl;
	}

	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"Span initiated to 4 elements, getting shortestSpan\033[m" \
		<< std::endl;
	{
		Span my_span(4);

		my_span.addNumber(13);
		my_span.addNumber(1);
		my_span.addNumber(43);
		my_span.addNumber(22);
		int shortest_span = my_span.shortestSpan();
		std::cout << "shortestSpan output: " << shortest_span  << std::endl;
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"Span initiated to 10 000\033[m" \
		<< std::endl;
	{
		Span my_span(10000);
		srand((unsigned int)time(NULL));

		for (int i = 0; i < 10000; i++)
		{
			my_span.addNumber(rand()%100000);
		}
		int shortest_span = my_span.shortestSpan();
		std::cout << "shortestSpan output: " << shortest_span  << std::endl;
		int longest_span = my_span.longestSpan();
		std::cout << "longestSpan output: " << longest_span  << std::endl;
		std::cout << "min was: " << my_span.getfirstForPeer()  << std::endl;
		std::cout << "max was: " << my_span.getLastForPeer()  << std::endl;
	}
	return (0);
}
