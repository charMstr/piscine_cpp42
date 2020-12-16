/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:31:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:40:31 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("RobotomyRequestForm", 72, 45),
	_target(target)	
{
	std::cout << "\033[33mconstructor called for Concrete Form (" << getName() \
		<< ")\033[0m" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Concrete Form (" \
		<< getName() << ")\033[0m" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	Form(src)
{
	*this = src;
	return ;
}

RobotomyRequestForm	&
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	return  (rhs.Serialize(o));
}

std::ostream &
RobotomyRequestForm::Serialize(std::ostream &o) const
{
	return Form::Serialize(o) << ", TARGET = " << getTarget() << std::endl;
}

void		
RobotomyRequestForm::actionOnTarget(void) const
{
	std::cout << "BzzzzBZzzzzBZZZZZZZ (drill noise)... " << getTarget() \
		<< " has been \"robotomizée\""  << std::endl;
}

std::string
RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}
