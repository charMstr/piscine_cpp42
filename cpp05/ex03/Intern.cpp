/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:14:42 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 12:28:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "MyException.hpp"
#include <exception>

Intern::Intern(void) :
	_nbKnownForms(3)
{
	std::cout << "\033[33mconstructor called for Intern.\033[0m" << std::endl;
	_knownForms[0] = "robotomy request";
	_knownForms[1] = "presidential pardon";
	_knownForms[2] = "shrubbery creation";
	_funcArray[0] = &Intern::createRobotomyRequestForm;
	_funcArray[1] = &Intern::createPresidentialPardonForm;
	_funcArray[2] = &Intern::createShrubberyCreationForm;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Intern)\033[0m" \
		<< std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	return ;
}

Intern	&
Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
	{
		;//put code here
	}
	return *this;
}

Form *
Intern::makeForm(std::string const &formName, \
		std::string const &target) const
{		
	try
	{
		for (int i = 0; i < _nbKnownForms; i++)
		{
			if (!formName.compare(_knownForms[i]))
			{
				std::cout << "Intern creates form " << formName << std::endl;
				Form *created = (this->*_funcArray[i])(target);
				return (created);
			}
		}
		throw MyException("Form:NameNotRecognized");
	}
	catch (std::exception const &e)
	{	
		std::cout << "Intern could not create form because: " << e.what() \
			<< std::endl;	
	}
	return (NULL);
}

Form *
Intern::createRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

Form *
Intern::createPresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

Form *
Intern::createShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}
