/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:52:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:04:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) :
	ClapTrap(name), //making sure we call the very base class with the
	//constructor taking the name as parameter.
	FragTrap(name),
	NinjaTrap(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_maxHitPoints = FragTrap::_maxHitPoints;
	_energyPoints = NinjaTrap::_energyPoints;
	_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	_rangeAttackDamage = FragTrap::_rangeAttackDamage;
	_armorDamageReduction = FragTrap::_armorDamageReduction;

	std::cout << "SUPER-TP: " << _name << "'s contructor called." << std::endl;
	return ;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUPER-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const &src) : FragTrap(src), NinjaTrap(src)
{
	std::cout << "SUPER-TP: " << _name << " constructed by copy." << std::endl;
	*this = src;
	return ;
}

SuperTrap	&
SuperTrap::operator=(SuperTrap const &rhs)
{
	if (this != &rhs)
	{
		_hitPoints = rhs.FragTrap::_hitPoints;
		_maxHitPoints = rhs.FragTrap::_maxHitPoints;
		_energyPoints = rhs.NinjaTrap::_energyPoints;
		_maxEnergyPoints = rhs.NinjaTrap::_maxEnergyPoints;
		_level = 1;
		_meleeAttackDamage = rhs.NinjaTrap::_meleeAttackDamage;
		_rangeAttackDamage = rhs.FragTrap::_rangeAttackDamage;
		_armorDamageReduction = rhs.FragTrap::_armorDamageReduction;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, SuperTrap const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


void
SuperTrap::rangedAttack(std::string const & target) const 
{
	FragTrap::rangedAttack(target);
}

void
SuperTrap::meleeAttack(std::string const & target) const
{
	NinjaTrap::meleeAttack(target);
}
