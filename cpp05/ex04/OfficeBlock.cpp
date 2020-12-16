/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:38:29 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 14:45:48 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

OfficeBlock::OfficeBlock(void) :
	_intern(0),
	_signator(0),
	_executor(0),
	_staffNumber(0),
	_createdForm(0)
{
	std::cout << "\033[33mconstructor called for OfficeBlock\033[0m" \
		<< std::endl;
	return ;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signator, \
		Bureaucrat* executor) :
	_intern(intern),
	_signator(signator),
	_executor(executor),
	_staffNumber(3),
	_createdForm(0)
{
	std::cout << "\033[33mconstructor called for OfficeBlock\033[0m" \
		<< std::endl;
	return ;
}

OfficeBlock::~OfficeBlock(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for "
		"OfficeBlock\033[0m" << std::endl;
	return ;
}

std::ostream	&
operator<<(std::ostream &o, OfficeBlock const &rhs)
{
	return rhs.Serialize(o);
}

std::ostream	&
OfficeBlock::Serialize(std::ostream &o) const
{
	o << "Intern ptr: " << _intern << std::endl \
		<< "Signator ptr: " << _signator << std::endl \
		<< "Executor ptr: " << _executor << std::endl
		<< "staff total number: " << _staffNumber << std::endl;
	return o;
}

void	
OfficeBlock::addInternToBlock(Intern *newbie)
{
	if (_intern)
	{
		std::cout << "There is already an Intern in the OfficeBlock" << \
			std::endl;
		return ;
	}
	_intern = newbie;
	_staffNumber += 1;
	std::cout << "Intern successfuly added to the OfficeBlock" << std::endl;
}

void	
OfficeBlock::addSignatorToBlock(Bureaucrat *signator)
{
	if (_signator)
	{
		std::cout << "There is already a Bureaucrat Signator in the OfficeBlock" << \
			std::endl;
		return ;
	}
	_signator = signator;
	_staffNumber += 1;
	std::cout << "Signator successfuly added to the OfficeBlock" << std::endl;
}

void
OfficeBlock::addExecutorToBlock(Bureaucrat *executor)
{
	if (_executor)
	{
		std::cout << "There is already a Bureaucrat executor in the OfficeBlock" << \
			std::endl;
		return ;
	}
	_executor = executor;
	_staffNumber += 1;
	std::cout << "Executor successfuly added to the OfficeBlock" << std::endl;
}

void
OfficeBlock::doBureaucracy(std::string const &formName, \
		std::string const &target)
{
	if (_staffNumber != 3)
	{
		std::cout << "Sorry no Bureaucracy can be done if some posts are " \
			"empty in the Office!" << std::endl;
		return ;
	}
	try
	{
		_createdForm = _intern->makeForm(formName, target);
		_signator->signForm(*_createdForm);
		_executor->executeForm(*_createdForm);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete _createdForm;
	_createdForm = NULL;
}
