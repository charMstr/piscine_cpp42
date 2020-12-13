/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:01:22 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:12:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100 ;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangeAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "FR4G-TP: " << _name << "'s contructor called." << std::endl;
	_attackRandom[0] = "Pock in the eye";
	_attackRandom[1] = "German suplex";
	_attackRandom[2] = "Curse your mum";
	_attackRandom[3] = "Pinch you nose";
	_attackRandom[4] = "Scream in you ear";

	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

//calling firs the constructor by copy of the Parent class, therefor copying
//the const _name for us, and all the common data
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
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
	std::cout  << "\033[31mFR4G-TP " << _name << " attaque " <<  target \
		<< " with random attack: \033[35m"  << _attackRandom[i] \
		<<  "!\033[m" << std::endl;
	return (1);
}
