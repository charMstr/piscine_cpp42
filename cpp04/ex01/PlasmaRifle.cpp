/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:22:45 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 11:22:32 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
	AWeapon("Plasma Rifle", 5, 21)
{
	return ;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src)
{
	*this = src;
	return ;
}

PlasmaRifle	&
PlasmaRifle::operator=(PlasmaRifle const &rhs)
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
//operator<<(std::ostream &o, PlasmaRifle const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


void
PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
