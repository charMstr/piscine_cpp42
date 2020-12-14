/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:49:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 11:22:36 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) :
	AWeapon("Power Fist", 8, 50)
{
	return ;
}

PowerFist::~PowerFist(void)
{
	return ;
}

PowerFist::PowerFist(PowerFist const &src)
{
	*this = src;
	return ;
}

PowerFist	&
PowerFist::operator=(PowerFist const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_apcost = rhs._apcost;
		_damage = rhs._damage;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, PowerFist const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

void 
PowerFist::attack() const
{
	std::cout <<  "* pschhh... SBAM ! *" << std::endl;
}
