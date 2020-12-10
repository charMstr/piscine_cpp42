/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:19:50 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 05:31:54 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "default";
	this->_type = "default";
}

Zombie::Zombie(std::string name, std::string type) :
	_name(name),
	_type(type)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "destructor called for: " << this->_name << "." << std::endl;
}

void 
Zombie::advert(void)
{
	std::cout << _name << " (" << _type << ")";
	std::cout << " Braiiiiiiinnnssss ..." << std::endl;
}
