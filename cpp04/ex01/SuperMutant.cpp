/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:25:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 12:21:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything !" << std::endl;
	return ;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const &src)
{
	*this = src;
	return ;
}

SuperMutant	&
SuperMutant::operator=(SuperMutant const &rhs)
{
	Enemy::operator=(rhs);	
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, SuperMutant const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

void	
SuperMutant::takeDamage(int d)
{
	Enemy::takeDamage(d - 3);
	return ;
}
