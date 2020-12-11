/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:19:21 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 06:48:48 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(void)
{
	return ;
}


void
HumanA::attack(void) const
{
	std::cout << _name << " attacks with his ";
	std::cout << _Weapon.getType() << "!" <<std::endl;
}

HumanA::HumanA(std::string name, Weapon &Weap) :
	_name(name),
	_Weapon(Weap)
{
	return ;
}
