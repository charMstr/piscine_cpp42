/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:01:22 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:22:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

FragTrap::FragTrap(std::string name) :
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
	std::cout << "FR4G-TP: " << _name << "'s contructor called." << std::endl;
	_attackRandom[0] = "Pock in the eye";
	_attackRandom[1] = "German suplex";
	_attackRandom[2] = "Curse your mum";
	_attackRandom[3] = "Pinch you nose";
	_attackRandom[4] = "Scream in you ear";

	 std::srand(std::time(NULL)); // use current time as seed for random generator
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FR4G-TP: " << _name << " constructed by copy." << std::endl;
	*this = src;
	return ;
}

FragTrap	&
FragTrap::operator=(FragTrap const &rhs)
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
//operator<<(std::ostream &o, FragTrap const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


void
FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "\033[31m" << std::endl;
	std::cout  << "FR4G-TP " << _name << " attaque " <<  target \
		<< " à distance, causant " << _rangeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

void
FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "\033[31m" << std::endl;
	std::cout << "FR4G-TP " << _name << " attaque " <<  target \
		<< " au corps a corps, causant " << _meleeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

int
FragTrap::takeDamage(unsigned int amount)
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
FragTrap::beRepaired(unsigned int amount)
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
FragTrap::getMeleeAttackDammage() const
{
	return (this->_meleeAttackDamage);
}
int

FragTrap::getRangeAttackDammage() const
{
	return (this->_rangeAttackDamage);
}

int
FragTrap::vaulthunter_dot_exe(std::string const & target)
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
	std::cout  << "FR4G-TP " << _name << " attaque " <<  target \
		<< " with random attack: \033[35m"  << _attackRandom[i] \
		<<  "!\033[m" << std::endl;
	return (1);
}
