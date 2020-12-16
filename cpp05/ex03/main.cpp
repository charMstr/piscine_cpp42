/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 12:30:59 by charmstr         ###   ########.fr       */
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

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" **************" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"instanciating Intern and try to make him create forms with mispeal\033[m" \
		<< std::endl << std::endl;
	{
		Intern Pesant;
		Pesant.makeForm("robotomy requesT", "my_target");
		Pesant.makeForm("shrubbery creatioN", "my_target");
		Pesant.makeForm("presidential pardoN", "my_target");
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"instanciating Intern and try to make him create 3 forms\033[m" \
		<< std::endl << std::endl;
	{
		Intern Pesant;
		Form *form1 = Pesant.makeForm("robotomy request", "my_target");
		std::cout << *form1 << std::endl;
		Form *form2 = Pesant.makeForm("shrubbery creation", "my_target");
		std::cout << *form2 << std::endl;
		Form *form3 = Pesant.makeForm("presidential pardon", "my_target");
		std::cout << *form3 << std::endl;
		delete form1;
		delete form2;
		delete form3;
	}
	//TEST 3)
	std::cout << std::endl << "\033[35mTEST 3) "
		"now just check those form can be signed.\033[m" \
		<< std::endl << std::endl;
	{
		Bureaucrat Charlie("Charlie", 1);
		Intern Pesant;
		Form *form1 = Pesant.makeForm("robotomy request", "my_target");
		std::cout << *form1 << std::endl;
		Charlie.signForm(*form1);
		std::cout << *form1 << std::endl;
		Charlie.executeForm(*form1);
		delete form1;
	}
		
	return (0);
}
