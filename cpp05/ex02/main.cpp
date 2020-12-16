/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 10:05:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "MyException.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" **************" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"instanciating ShrubberyCreationForm with target maison\033[m" \
		<< std::endl << std::endl;
	{
		Form	*form1 = new ShrubberyCreationForm("maison");	

		std::cout << *form1;
		delete form1;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"instanciating ShrubberyCreationForm and executing without signing it.\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Charlie("Charlie", 1);
		Form	*form1 = new ShrubberyCreationForm("maison");	
		std::cout << *form1;
		try { form1->execute(Charlie); }
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;	
		}
		form1->beSigned(Charlie);
		std::cout << *form1;
		try { form1->execute(Charlie); }
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;	
		}
		std::cout << "	==> verify that the file maison_shrubbery has been created..." << std::endl;
		delete form1;
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"instanciating PresidentialPardonForm and get the bureaucrat to execute it\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Charlie("Charlie", 6);
		Form	*form1 = new PresidentialPardonForm("Victim_from_42");
		form1->beSigned(Charlie);
		std::cout << Charlie;
		std::cout << *form1;
		Charlie.executeForm(*form1);
		Charlie.incGrade();
		std::cout << std::endl << Charlie;
		Charlie.executeForm(*form1);
		delete form1;
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"instanciating RobotomyRequestForm and get the bureaucrat to execute it\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Charlie("Charlie", 46);
		Form	*form1 = new RobotomyRequestForm("Victim_from_42");
		std::cout << Charlie;
		std::cout << *form1;
		Charlie.executeForm(*form1);
		std::cout << std::endl;
		form1->beSigned(Charlie);
		std::cout << Charlie;
		std::cout << *form1;
		Charlie.executeForm(*form1);
		std::cout << std::endl;
		Charlie.incGrade();
		std::cout << Charlie;
		std::cout << *form1;
		Charlie.executeForm(*form1);
		delete form1;
	}
	return (0);
}
