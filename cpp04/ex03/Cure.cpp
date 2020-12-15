/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:50:47 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 10:45:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure(void) :
	AMateria("cure")
{
	return ;
}

Cure::~Cure(void)
{
	return ;
}

Cure::Cure(Cure const &src)
{
	*this = src;
	return ;
}

Cure	&
Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, Cure const &rhs)
//{
//	o << rhs.getValue();
//	return o;
//}


AMateria*
Cure::clone() const
{
	return (new Cure);	
}


void
Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
