/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:54 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 03:55:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Bureaucrat.hpp"
#include "MyException.hpp"
#include <exception>

//note to peer: doing so, i can avoid the constructor message at all if an
//exception is thrown
Bureaucrat::Bureaucrat(std::string const name, int grade) :
	_name(name),
	_grade(checkGrade(grade))
{
	std::cout << "\033[33mconstructor called for Bureaucrat (" << getName() \
		<< ")\033[0m" << std::endl;
	return ;
}

//exception thrower for the constructor
int
Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw MyException("Bureaucrat::GradeTooHighException");
	else if (grade > 150)
		throw MyException("Bureaucrat::GradeTooLowException");
	return (grade);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Bureaucrat (" \
		<< getName() << ")\033[0m" << std::endl;
	return ;
}

//copy the right hand side in the initialisation list at the start.
Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
	return ;
}

Bureaucrat	&
Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." \
		<< std::endl;
	return o;
}

std::string const &
Bureaucrat::getName(void) const
{
	return _name;
}

int					
Bureaucrat::getGrade(void) const
{
	return _grade;
}

void			
Bureaucrat::incGrade(void)
{
	if (_grade == 1)
		return ;
	_grade--;
}

void				
Bureaucrat::decGrade(void)
{
	if (_grade == 150)
		return ;
	_grade++;
}
