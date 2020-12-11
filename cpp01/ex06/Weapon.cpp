/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:10:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 06:30:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const &
Weapon::getType(void) const
{
	return (this->_type);
}

void
Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon(std::string type)
{
	 this->_type = type;
}
