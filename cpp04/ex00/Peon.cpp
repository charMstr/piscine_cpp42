/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:48 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 09:32:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{	
	std::cout << "Zog zog."  << std::endl;
	return ;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}

//directrly call the copy constructor from the base class, with the parameter
//being passed allong.
Peon::Peon(Peon const &src) : Victim(src)
{
	std::cout << "Zog zog."  << std::endl;
	return ;
}


Peon	&
Peon::operator=(Peon const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
	}
	return *this;
}

//no need to overload the existing thing in parent class.
//std::ostream	&
//operator<<(std::ostream &o, Peon const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

void
Peon::getPolymorphed() const
{
	std::cout << "\033[34m" << _name \
		<<" was just polymorphed into a pink pony!\033[0m" << std::endl;
}
