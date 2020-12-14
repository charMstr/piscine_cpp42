/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:54:37 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 16:56:59 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp),
	_type(type)
{
	std::cout << "\033[33mconstructor called for (Enemy) " << _type \
		<< "\033[m" << std::endl;
	return ;
}

Enemy::~Enemy(void)
{
	std::cout << "\033[33mdestructor called for (Enemy) " << _type \
		<< "\033[m" << std::endl;
	return ;
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
	return ;
}

Enemy	&
Enemy::operator=(Enemy const &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
		_hp = rhs.getHP();
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, Enemy const &i)
//{
//	o << rhs.getValue();
//	return o;
//}
std::string		
Enemy::getType() const
{
	return (this->_type);	
}

int				
Enemy::getHP() const
{
	return (this->_hp);
}

void
Enemy::setHP(int new_hp)
{
	_hp =  new_hp;
}

void			
Enemy::setType(std::string const &type)
{
	_type = type;
}

void	
Enemy::takeDamage(int d)
{
	if (d <= 0)
		return ;
	_hp -= d;
	if (_hp < 0)
		_hp = 0;
	if (_hp == 0)
		std::cout << "\033[32m" << _type << " takes " << d\
			<< " of damages and dies!\033[m" << std::endl;
	else
		std::cout << "\033[32m" << _type << " takes " << d <<\
			" of damages and has " << _hp << " left!\033[m" << std::endl;
}
