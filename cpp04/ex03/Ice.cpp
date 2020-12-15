/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:55:58 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 12:09:16 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice(void) :
	AMateria("ice")
{
	return ;
}

Ice::~Ice(void)
{
	return ;
}

Ice::Ice(Ice const &src) 
{
	*this = src;
	return ;
}

Ice	&
Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, Ice const &rhs)
//{
//	o << rhs.getValue();
//	return o;
//}

AMateria*
Ice::clone() const
{
	return (new Ice);	
}


void
Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"\
		<< std::endl;
}
