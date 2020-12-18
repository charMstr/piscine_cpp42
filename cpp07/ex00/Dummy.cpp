/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:45:29 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 09:51:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Dummy.hpp"

Dummy::Dummy(int i) :
	_i(i)
{
	return ;
}

Dummy::~Dummy(void)
{
	return ;
}

Dummy::Dummy(Dummy const &src)
{
	*this = src;
	return ;
}

Dummy	&
Dummy::operator=(Dummy const &rhs)
{
	if (this != &rhs)
	{
		_i = rhs._i;
		;//put code here
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Dummy const &rhs)
{
	return rhs.Serialize(o);
}

std::ostream	&
Dummy::Serialize(std::ostream &o) const
{
	o << _i << std::endl; //or something else
	return o;
	//return BASE::Serialize(o) << getName()...;
}

//MY OVERlOADS
bool
Dummy::operator==(Dummy const &rhs) const
{
	if (_i == rhs._i)
		return (true);
	return (false);
}

bool
Dummy::operator<(Dummy const &rhs) const
{
	if (_i < rhs._i)
		return (true);
	return (false);
}

bool
Dummy::operator>(Dummy const &rhs) const
{
	if (_i > rhs._i)
		return (true);
	return (false);
}
