/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:07:25 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 07:30:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

ScavTrap::ScavTrap(std::string name) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_name(name),
	_meleeAttackDamage(20),
	_rangeAttackDamage(15),
	_armorDamageReduction(3)
{
	std::cout << "CL4P-TP: " << _name << "'s contructor called." << std::endl;
	_attackRandom[0] = "Try to touch you nose with your Tongue!";
	_attackRandom[1] = "Try to give me a German suplex!";
	_attackRandom[2] = "Up for a little roll on the ground?";
	_attackRandom[3] = "eat a red pepper!";
	_attackRandom[4] = "give ten points to the pool!";

	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "CL4P-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "CL4P-TP: " << _name << " constructed by copy." << std::endl;
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
		_name = rhs._name;
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
	std::cout << "\033[31m" << std::endl;
	std::cout  << "CL4P-TP " << _name << " attaque " <<  target \
		<< " à distance, causant " << _rangeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

void
ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "\033[31m" << std::endl;
	std::cout << "CL4P-TP " << _name << " attaque " <<  target \
		<< " au corps a corps, causant " << _meleeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

int
ScavTrap::takeDamage(unsigned int amount)
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
ScavTrap::beRepaired(unsigned int amount)
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
ScavTrap::getMeleeAttackDammage() const
{
	return (this->_meleeAttackDamage);
}
int

ScavTrap::getRangeAttackDammage() const
{
	return (this->_rangeAttackDamage);
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
	std::cout << "\033[31m" << std::endl;
	std::cout  << "CL4P-TP " << _name << " challenges " <<  target \
		<< " with random challenge: \033[35m"  << _attackRandom[i] \
		<<  "!\033[m" << std::endl;
	return (1);
}
