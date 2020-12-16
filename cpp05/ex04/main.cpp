/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 14:55:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "MyException.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "OfficeBlock.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" **************" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"OfficeBlock created without arguments\033[m" \
		<< std::endl << std::endl;
	{
		OfficeBlock Block;
		std::cout << Block << std::endl;
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"OfficeBlock created with 3 staff members\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Edmund("Edmund", 42);
		Intern Francis;
		Bureaucrat Jean("Jean", 12);
		//OfficeBlock Block(&Francis);
		OfficeBlock Block(&Francis, &Edmund, &Jean);
		std::cout << Block << std::endl;
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"OfficeBlock created empty and adding staff members\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Edmund("Edmund", 42);
		Intern Francis;
		Bureaucrat Jean("Jean", 12);
		OfficeBlock Block;
		std::cout << Block << std::endl;
		Block.addExecutorToBlock(&Jean);
		std::cout << Block << std::endl;
		Block.addExecutorToBlock(&Jean);
		std::cout << Block << std::endl;
		Block.addSignatorToBlock(&Edmund);
		std::cout << Block << std::endl;
		Block.addInternToBlock(&Francis);
		std::cout << Block << std::endl;
	}
	//TEST 4)
	std::cout << std::endl << "\033[35mTEST 4) "
		"OfficeBlock withouth a full team to work\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Edmund("Edmund", 42);
		Intern Francis;
		OfficeBlock Block;
		Block.addSignatorToBlock(&Edmund);
		Block.addInternToBlock(&Francis);
		std::cout << Block << std::endl;
		Block.doBureaucracy("dummy_form", "dummy_target");
	}
	//TEST 5)
	std::cout << std::endl << "\033[35mTEST 5) "
		"OfficeBlock created with full staff, trying to doBureaucracy!\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Signator_Edmund("signator_Edmund", 73);
		Intern Francis;
		Bureaucrat Executor_Jean("executor_Jean", 46);
		OfficeBlock Block(&Francis, &Signator_Edmund, &Executor_Jean);
		std::cout << Block << std::endl;
		Block.doBureaucracy("robotomy requesT", "my_target");
		std::cout << "" << std::endl;
		Block.doBureaucracy("robotomy request", "my_target");
		std::cout << std::endl << Signator_Edmund << std::endl;
		std::cout << "increasing the level for the signator and try again..." << std::endl;
		Signator_Edmund.incGrade();
		Block.doBureaucracy("robotomy request", "my_target");
		std::cout << std::endl << Executor_Jean << std::endl;
		std::cout << "increasing the level for the executor and try again..." << std::endl;
		Executor_Jean.incGrade();
		Block.doBureaucracy("robotomy request", "my_target");
	}
		
	return (0);
}
