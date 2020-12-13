/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:07:25 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:12:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

//using the constructor in the initialisation list. allows me to have _name
// as a constant variable.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangeAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "SC4V-TP: " << _name << "'s contructor called." << std::endl;
	_attackRandom[0] = "Try to touch you nose with your Tongue!";
	_attackRandom[1] = "Try to give me a German suplex!";
	_attackRandom[2] = "Up for a little roll on the ground?";
	_attackRandom[3] = "eat a red pepper!";
	_attackRandom[4] = "give ten points to the pool!";

	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

//calling firs the constructor by copy of the Parent class, therefor copying
//the const _name for us, and all the common data
ScavTrap::ScavTrap(ScavTrap const &src) :ClapTrap(src)
{
	std::cout << "SC4V-TP: " << _name << " constructed by copy." << std::endl;
	*this = src;
	return ;
}

ScavTrap	&
ScavTrap::operator=(ScavTrap const &rhs)
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
		_attackRandom[0] = rhs._attackRandom[0];
		_attackRandom[1] = rhs._attackRandom[1];
		_attackRandom[2] = rhs._attackRandom[2];
		_attackRandom[3] = rhs._attackRandom[3];
		_attackRandom[4] = rhs._attackRandom[4];
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, ScavTrap const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

void
ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout  << "\033[31m"<< "SC4V-TP " << _name << " attaque " <<  target \
		<< " à distance, causant " << _rangeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

void
ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "\033[31m"<< "SC4V-TP " << _name << " attaque " <<  target \
		<< " au corps a corps, causant " << _meleeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

int
ScavTrap::challengeNewcomer(std::string const & target)
{
    int i = std::rand() % 5;

	_energyPoints -= 25;
	if (_energyPoints < 0)
	{
		_energyPoints = 0;
		std::cout << "Damn it, not enough energy!" << std::endl;
		return (0);
	}
	std::cout  << "\033[31mSC4V-TP " << _name << " challenges " <<  target \
		<< " with random challenge: \033[35m"  << _attackRandom[i] \
		<<  "!\033[m" << std::endl;
	return (1);
}
