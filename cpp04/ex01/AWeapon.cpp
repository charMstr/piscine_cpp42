/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:05:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 16:58:05 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
	_name(name),
	_apcost(apcost),
	_damage(damage)
{
	std::cout << "\033[33mconstructor called for " << _name \
		<< "\033[m" << std::endl;
	return ;
}

AWeapon::~AWeapon(void)
{
	std::cout << "\033[33mdestructor called for " << _name \
		<< "\033[m" << std::endl;
	return ;
}

AWeapon::AWeapon(AWeapon const &src)
{
	*this = src;
	return ;
}

AWeapon	&
AWeapon::operator=(AWeapon const &rhs) 
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_apcost = rhs._apcost;//put code here
		_damage = rhs._damage;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, AWeapon const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

std::string
AWeapon::getName() const
{
	return (this->_name);
}

int
AWeapon::getAPCost() const
{
	return (this->_apcost);
}

int						
AWeapon::getDamage() const
{
	return (this->_damage);
}
