/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 04:11:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 05:26:18 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Form.hpp"
#include "MyException.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(checkGradeToSign(gradeToSign)),
	_gradeToExecute(checkGradeToExecute(gradeToExecute, gradeToSign)),
	_signed(0)
{
	std::cout << "\033[33mconstructor called for Form (" << getName() \
		<< ")\033[0m" << std::endl;
	return ;
}

//exception thrower for the constructor
int
Form::checkGradeToSign(int gradeToSign) const
{
	if (gradeToSign < 1)
		throw MyException("Form::GradeTooHighException");
	if (gradeToSign > 150)
		throw MyException("Form::GradeTooLowException");
	return (gradeToSign);
}
//exception thrower for thr constructor
int
Form::checkGradeToExecute(int gradeToExecute, int gradeToSign) const
{
	if (gradeToExecute < 1)
		throw MyException("Form::GradeTooHighException");
	else if (gradeToExecute > 150)
		throw MyException("Form::GradeTooLowException");
	//added a case if grade to sign is lower than grade to execute, non sens!
	else if (gradeToExecute < gradeToSign)
		throw MyException("Form::GradeIllogical");
	return (gradeToExecute);
}

Form::~Form(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Bureaucrat (" \
		<< getName() << ")\033[0m" << std::endl;
	return ;
}

Form::Form(Form const &src) :
	_name(src._name),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	*this = src;
	return ;
}

Form	&
Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Form const &rhs)
{
	o << "form " << rhs.getName() << ": "; \
	if (rhs.getSigned())
		o << "[SIGNED]";
	else
		o << "[NOT SIGNED YET]";
	o << " (gradeToSign: " << rhs.getGradeToSign() << ", gradeToExecute: "\
		<< rhs.getGradeToExecute() << ")" << std::endl;
	return o;
}

std::string const &
Form::getName(void) const
{
	return _name;
}

int					
Form::getSigned(void) const
{
	return _signed;
}

int					
Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int					
Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void 				
Form::beSigned(Bureaucrat const &who)
{
	//check if the bureaucrat doesnt have a grade too low.
	if (getGradeToSign() < who.getGrade())
		throw MyException("Form::GradeTooLowException");
	_signed = true;
}
