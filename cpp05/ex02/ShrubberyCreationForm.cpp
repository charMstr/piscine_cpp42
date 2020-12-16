/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 05:54:44 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:26:22 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "MyException.hpp"
#include <fstream>
#include <sstream>

//we first make a call to the Abstract class constructor.
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	Form("ShrubberyCreationForm",  145, 137),
	_target(target)	
{
	std::cout << "\033[33mconstructor called for Concrete Form (" << getName() \
		<< ")\033[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "\033[31m[~]\033[33mdestructor called for Concrete Form (" \
		<< getName() << ")\033[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	Form(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm	&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		_target = rhs.getTarget();
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	return  (rhs.Serialize(o));
}

std::ostream &
ShrubberyCreationForm::Serialize(std::ostream &o) const
{
	return Form::Serialize(o) << ", TARGET = " << getTarget() << std::endl;
}

void		
ShrubberyCreationForm::actionOnTarget(void) const
{
	std::stringstream ss(getTarget(), std::ios_base::app | std::ios_base::out);
	ss << "_shrubbery";
	std::ofstream ofs (ss.str().c_str(), std::ofstream::app);
	if (!ofs.is_open())
	{
		throw std::runtime_error("Could not open file");
	}
	_drawTree(ofs);
 	ofs.close();
}

void
ShrubberyCreationForm::_drawTree(std::ostream &o) const
{
	o << "                                              ." << std::endl;
	o << "                                   .         ;" << std::endl;
	o << "      .              .              ;%     ;;" << std::endl;
	o << "        ,           ,                :;%  %;" << std::endl;
	o << "         :         ;                   :;%;'     .," << std::endl;
	o << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	o << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	o << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	o << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	o << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	o << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	o << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	o << "           `@%:.  :;%.         ;@@%;'" << std::endl;
	o << "             `@%.  `;@%.      ;@@%;" << std::endl;
	o << "               `@%%. `@%%    ;@@%;" << std::endl;
	o << "                 ;@%. :@%%  %@@%;" << std::endl;
	o << "                   %@bd%%%bd%%:;" << std::endl;
	o << "                     #@%%%%%:;;" << std::endl;
	o << "                     %@@%%%::;" << std::endl;
	o << "                     %@@@%(o);  . '" << std::endl;
	o << "                     %@@@o%;:(.,'" << std::endl;
	o << "                 `.. %@@@o%::;" << std::endl;
	o << "                    `)@@@o%::;" << std::endl;
	o << "                     %@@(o)::;" << std::endl;
	o << "                    .%@@@@%::;" << std::endl;
	o << "                    ;%@@@@%::;." << std::endl;
	o << "                   ;%@@@@%%:;;;." << std::endl;
	o << "               ...;%@@@@@%%:;;;;,..	 Stolen." << std::endl;
	o << "" << std::endl;
}

std::string
ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}
