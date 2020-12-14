/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:05:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 13:09:45 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const &src)
{
	*this = src;
	return ;
}

RadScorpion	&
RadScorpion::operator=(RadScorpion const &rhs)
{
	Enemy::operator=(rhs);	
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, RadScorpion const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

//void	
//RadScorpion::takeDamage(int d)
//{
//	Enemy::takeDamage(d - 3);
//	return ;
//}

