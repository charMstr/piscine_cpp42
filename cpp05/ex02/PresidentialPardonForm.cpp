/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:41:07 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:56:32 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("PresidentialPardonForm", 25, 5),
	_target(target)	
{
	std::cout << "\033[33mconstructor called for Concrete Form (" << getName() \
		<< ")\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Concrete Form (" \
		<< getName() << ")\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	Form(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm	&
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	return  (rhs.Serialize(o));
}

std::ostream &
PresidentialPardonForm::Serialize(std::ostream &o) const
{
	return Form::Serialize(o) << ", TARGET = " << getTarget() << std::endl;
}

void		
PresidentialPardonForm::actionOnTarget(void) const
{
	std::cout << getTarget() << " has been forgiven by Zafod Beeblebrox" \
		<< std::endl;
}

std::string
PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}
