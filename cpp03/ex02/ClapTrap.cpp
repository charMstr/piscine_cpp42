/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:37:58 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 08:18:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_name(name),
	_meleeAttackDamage(30),
	_rangeAttackDamage(20),
	_armorDamageReduction(5)
{
	std::cout << "CL4P-TP: " << _name << "'s contructor called." << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

//setting the const _name in the initialisation list
ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name)
{
	std::cout << "CL4P-TP: " << _name << " constructed by copy." << std::endl;
	*this = src;
	return ;
}

ClapTrap	&
ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		_hitPoints = rhs._hitPoints;
		_maxHitPoints = rhs._maxHitPoints;
		_energyPoints = rhs._energyPoints;
		_maxEnergyPoints = rhs._maxEnergyPoints;
		_level = rhs._level;
		_meleeAttackDamage = rhs._meleeAttackDamage;
		_rangeAttackDamage = rhs._rangeAttackDamage;
		_armorDamageReduction = rhs._armorDamageReduction;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, ClapTrap const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


void
ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << "\033[31m" << std::endl;
	std::cout  << "CL4P-TP " << _name << " attaque " <<  target \
		<< " à distance, causant " << _rangeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

void
ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << "\033[31m" << std::endl;
	std::cout << "CL4P-TP " << _name << " attaque " <<  target \
		<< " au corps a corps, causant " << _meleeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

int
ClapTrap::takeDamage(unsigned int amount)
{
	int damage = amount - _armorDamageReduction;

	std::cout << "\033[33m" << std::endl;
	if (damage < 0)
	{
		std::cout << _name << "'s armor took all the damage." \
			<< "\033[m" << std::endl;
		return (1);	
	}
	if (damage > _hitPoints)
		damage = _hitPoints;
	_hitPoints = _hitPoints - damage;
	std::cout << _name << " takes " << amount << " damage..."  << std::endl;
	std::cout << "but his armor took in " << _armorDamageReduction \
		<< " of the inflicted damage." << std::endl;
	if (_hitPoints == 0)
	{
		std::cout << "now " << _name << " is dead!" << "\033[m" << std::endl;
		return (0);
	}
	else
		std::cout << "now " << _name << " has " << _hitPoints << " left."\
			<< "\033[m" << std::endl;
	return (1);
}

void
ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints = amount + _hitPoints;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << "\033[32m" << std::endl;
	std::cout << _name << " got his hit points repaired to: " << _hitPoints;
	if (_maxHitPoints == _hitPoints)
		std::cout << "(max)";
	std::cout << "\033[m" << std::endl;
}

int
ClapTrap::getMeleeAttackDammage() const
{
	return (this->_meleeAttackDamage);
}
int

ClapTrap::getRangeAttackDammage() const
{
	return (this->_rangeAttackDamage);
}
