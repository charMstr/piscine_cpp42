/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 07:09:13 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 10:09:37 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string name) :
	_name(name)

{
	//setting the name to upper case.
	for (size_t i = 0; i < _name.length(); i++)
		_name[i] = toupper(_name[i]);
	std::cout << "A random victim called "<< _name << " just appeared!"\
		<< std::endl;
	return ;
}

Victim::~Victim(void)
{
	std::cout << "The victim " << _name <<  " died for no apparent reasons!"\
		<< std::endl;
	return ;
}

Victim::Victim(Victim const &src)
{
	*this = src;
	std::cout << "A random victim called "<< _name << " just appeared!"\
		"\033[33m (by copy)\033[m" << std::endl;
	return ;
}

Victim	&
Victim::operator=(Victim const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Victim const &rhs)
{
	o << "\033[32mI'm " << rhs.getName() << " and I like otters!\033[m"\
		<< std::endl;
	return o;
}

std::string const
Victim::getName() const
{
	return (this->_name);
}

void
Victim::getPolymorphed() const
{
	std::cout << "\033[34m" << _name << " was just polymorphed in a cute"\
		" little sheep!\033[0m" << std::endl;
}
