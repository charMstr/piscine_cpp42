/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:26:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 21:09:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I’ll be back ..." << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src)
{
	*this = src;
	return ;
}

AssaultTerminator	&
AssaultTerminator::operator=(AssaultTerminator const &rhs)
{
	if (this != &rhs)
	{
		//no data to copy so far 
		;//put code here
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, AssaultTerminator const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


ISpaceMarine*
AssaultTerminator::clone() const //OK
{
	AssaultTerminator *cloned = new AssaultTerminator;
//	*cloned = AssaultTerminator(*this);
	return (cloned);
}

void
AssaultTerminator::battleCry() const //OK
{
	std::cout << "This code is unclean. Purify it !" << std::endl;	
}

void
AssaultTerminator::rangedAttack() const //OK
{
	std::cout << "* does nothing *" << std::endl;
}

void
AssaultTerminator::meleeAttack() const //OK
{
	std::cout << "* attaque with chainfists *" << std::endl;
}
