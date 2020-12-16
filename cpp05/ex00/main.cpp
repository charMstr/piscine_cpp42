/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 04:09:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "MyException.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "NOTE TO PEER:" << std::endl \
		<< "I managed withing the constructor to stop creating the object" \
		" if the grade is too low or toow high" << std::endl << std::endl;
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" **************" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"instanciating with grade 0\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 0);
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"instanciating with grade 1, OK\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 1);
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"instanciating with grade 151\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 151);
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"instanciating with grade 150, OK\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 150);
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"instanciating with grade 150, incresing grade once, then" \
		" decreasing grade twice\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 150);
			std::cout  << Guy1;
			Guy1.incGrade();
			std::cout  << Guy1;
			Guy1.decGrade();
			std::cout  << Guy1;
			Guy1.decGrade();
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"instanciating with grade 1, decreasing grade once, then" \
		" increasing grade twice\033[m" \
		<< std::endl;
	{
		try
		{
			Bureaucrat Guy1("antony", 1);
			std::cout  << Guy1;
			Guy1.decGrade();
			std::cout  << Guy1;
			Guy1.incGrade();
			std::cout  << Guy1;
			Guy1.incGrade();
			std::cout  << Guy1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
