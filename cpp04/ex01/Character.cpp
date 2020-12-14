/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:12:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 16:59:23 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Character.hpp"

Character::Character(std::string const & name) :
	_name(name),
	_aP(40),
	_weapon(NULL)
{
	std::cout << "\033[33mconstructor called for (character) " << _name\
		<< "\033[0m" << std::endl;
	return ;
}

Character::~Character(void)
{
	std::cout << "\033[33mdestructor called for (character) " << _name\
		<< "\033[0m" << std::endl;
	return ;
}

Character::Character(Character const &src)
{
	std::cout << "\033[33m(copy) constructor called for (character) " << _name\
		<< "\033[0m" << std::endl;
	*this = src;
	return ;
}

Character	&
Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		setName(rhs.getName());
		setAP(rhs.getAP());
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Character const &rhs)
{
	//if it has a weapon
	if (rhs.getWeapon())
	{
		o << rhs.getName() << " has " << rhs.getAP()\
			<< " AP and carries a " << rhs.getWeapon()->getName()\
			<< std::endl;
	}
	else
	{
		o << rhs.getName() << " has " << rhs.getAP()\
			<< " AP and is unarmed" << std::endl;
	}
	return o;
}

std::string const
Character::getName() const
{
	return (this->_name);
}

void			
Character::setName(std::string const &name)
{
	_name = name;
}

void
Character::recoverAP()
{
	setAP(this->getAP() + 10);
	if (getAP() > 40)
		setAP(40);
	std::cout << "\033[312m" << _name << " recovered 10 AP and now has: "\
		<< getAP() <<  " AP.\033[m" << std::endl;
}

void
Character::equip(AWeapon *weapon)
{
	_weapon = weapon;
}

AWeapon	const *
Character::getWeapon(void) const
{
	return (this->_weapon);
}

void
Character::attack(Enemy* target)
{
	//si pas d'ap, pas d'attaque
	if (_weapon == NULL)
	{
		std::cout << _name << "* click click click *" << std::endl;
		return ;
	}
	else if (_weapon->getAPCost() > getAP())
	{
		std::cout << "\033[32m" << _name << " has not enough AP to use "\
			<< _weapon->getName() << "\033[m" << std::endl;
		return ;
	}
	std::cout << getName() <<  " attaque " <<  target->getType()\
		<< " with a " << _weapon->getName() << std::endl;
	setAP(getAP() - _weapon->getAPCost());
	_weapon->attack();
	target->takeDamage(_weapon->getDamage());
	
	if (target->getHP() <= 0)
		//note: if we use the target->~Enemy(); destructor, it will be
		//called again at the end of the main -> undefined behavior
		//the proper way would be in the code to now the enemy is dead, 
		//so that we dont attack him again
		delete target;
}

void
Character::setAP(int ap)
{
	_aP = ap;
}

int
Character::getAP(void) const
{
	return (_aP);
}
