/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:06:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:13:10 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120 ;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangeAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "NINJ4-TP: " << _name << "'s contructor called." << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NINJ4-TP: " << _name << " has been destroyed!" << std::endl;
	return ;
}

//calling firs the constructor by copy of the Parent class, therefor copying
//the const _name for us, and all the common data
NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
	std::cout << "NINJ4-TP: " << _name << " constructed by copy." << std::endl;
	*this = src;
	return ;
}

NinjaTrap	&
NinjaTrap::operator=(NinjaTrap const &rhs)
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

void
NinjaTrap::rangedAttack(std::string const & target) const
{
	std::cout  << "\033[31mNINJ4-TP " << _name << " attaque " <<  target \
		<< " à distance, causant " << _rangeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

void
NinjaTrap::meleeAttack(std::string const & target) const
{
	std::cout << "\033[31mNINJ4-TP " << _name << " attaque " <<  target \
		<< " au corps a corps, causant " << _meleeAttackDamage \
		<<  " points de dégâts !\033[m" << std::endl;
}

//std::ostream	&
//operator<<(std::ostream &o, NinjaTrap const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


//function to attack another NinjaTrap
void
NinjaTrap::ninjaShoebox(NinjaTrap &inst) const
{
	if (this == &inst)
	{
		std::cout << "NINJ4-TP " << "Dont Attack yourself you mental!" << std::endl;
		return ;
	}
	std::cout << "NINJ4-TP " << _name << " attacks (another NinjaTrap) " << inst._name \
		<< "\033[35m and sends him a shoe right in the face.\033[m" << std::endl;
}

//function to attack a ClapTrap
void
NinjaTrap::ninjaShoebox(ClapTrap &inst) const
{
	std::cout << "NINJ4-TP " << _name << " attacks (a ClapTrap) " << inst.getName() \
		<< "\033[36m and kicks him in the nuts.\033[m" << std::endl;
}

//function to attack a FragTrap
void
NinjaTrap::ninjaShoebox(FragTrap &inst) const
{
	std::cout << "NINJ4-TP " << _name << " attacks (a FragTrap) " << inst.getName() \
		<< "\033[32m and cuts his toes (brutal!)\033[m" << std::endl;
}

//function to attack a FragTrap
void
NinjaTrap::ninjaShoebox(ScavTrap &inst) const
{
	std::cout << "NINJ4-TP " << _name << " attacks (a ScavTrap) " << inst.getName() \
		<< "\033[33m and squashes his wheels(sick!)\033[m" << std::endl;
}
