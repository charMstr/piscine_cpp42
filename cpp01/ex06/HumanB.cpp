/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:49:09 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 07:06:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::~HumanB(void)
{
	return ;
}

void
HumanB::attack(void) const
{
	std::cout << _name << " attacks with his ";
	if (!_Weapon)
	{
		std::cout << "nothing!" << std::endl;
		return ;
	}
	std::cout << _Weapon->getType() << "!" <<std::endl;
}

HumanB::HumanB(std::string name) :
	_name(name)
{
	_Weapon = NULL;
	return ;
}

void
HumanB::setWeapon(Weapon &Weap)
{
	_Weapon = &Weap;
}
