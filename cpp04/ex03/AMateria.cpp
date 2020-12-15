/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:37:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 10:51:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) :
	_type(type),
	_xp(0)
{
	std::cout << "\033[33mconstructor called for AMateria (" << _type \
		<< ")\033[0m" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "\033[33mdestructor called for AMateria (" << _type \
		<< ")\033[0m" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	return ;
}

AMateria	&
AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		_xp = rhs._xp;
		//the subject says that doing so does not make sens... whatever
		//_type = rhs._type;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, AMateria const &rhs)
//{
//	o << rhs.getValue();
//	return o;
//}

void			
AMateria::incXP(int inc)
{
	_xp += inc;
}

std::string const &
AMateria::getType(void) const //Returns the materia type
{
	return (_type);
}

unsigned int	
AMateria::getXP(void) const //Returns the Materia's XP
{
	return (_xp);
}

void		
AMateria::use(ICharacter &target)
{
	(void)target; //do something on target...
	incXP();
}
