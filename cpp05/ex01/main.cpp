/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 05:52:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "MyException.hpp"
#include "Form.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" **************" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"instanciating Form called 42_form1, with default values\033[m" \
		<< std::endl << std::endl;
	{
		try
		{
			Form Form1("42_form1");
			std::cout  << Form1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"instanciating Form with  0 for gradeToSign or getGradeToExecute\033[m" \
		<< std::endl << std::endl;
	{
		try
		{
			Form Form1("42_form1", 0, 42);
			std::cout  << Form1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form Form1("42_form1", 42, 0);
			std::cout  << Form1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"instanciating Form with  151 for gradeToSign or getGradeToExecute\033[m" \
		<< std::endl << std::endl;
	{
		try
		{
			Form Form1("42_form1", 151, 42);
			std::cout  << Form1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form Form1("42_form1", 42, 151);
			std::cout  << Form1;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"instanciating Bureaucrat and try to sign form\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Guy1("Bill", 42);
		Form Form1("42_form", 41, 50);
		std::cout << Guy1;
		std::cout << Form1;
		Guy1.signForm(Form1);
		std::cout << Form1;
		std::cout << std::endl;
		std::cout << "\033[32m pretend Bill got promoted...\033[m" << std::endl;
		Guy1.incGrade();
		std::cout << Guy1;
		Guy1.signForm(Form1);
		std::cout << Form1;
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"trying to sign twice the same form\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Guy1("Bill", 42);
		Form Form1("42_form", 42, 50);
		std::cout << Guy1;
		std::cout << Form1;
		Guy1.signForm(Form1);
		std::cout << Form1;
		std::cout << "trying to sign again..." << std::endl;
		Guy1.signForm(Form1);
	}
	return (0);
}
