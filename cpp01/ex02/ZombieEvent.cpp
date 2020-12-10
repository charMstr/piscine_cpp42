/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:57:11 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 06:44:08 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void)
{
	initRandomNames();
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}

void 
ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie* 
ZombieEvent::newZombie (std::string name)
{
	return(new Zombie(name, this->_type));
}


Zombie*
ZombieEvent::randomChump(void)
{
	int	randomNumber;
	Zombie *newRandom;

	srand (time(NULL));
	randomNumber =  rand() % 5;
	newRandom = new Zombie(this->_randomNames[randomNumber], this->_type);
	this->announce(this->_randomNames[randomNumber]);
	return (newRandom);
}

void
ZombieEvent::announce(std::string name)
{
	std::cout << "BOOUH! I'm " << name << " (" << this->_type << ")." << std::endl;
}

//private functions************************************************************

void
ZombieEvent::initRandomNames(void)
{
	this->_randomNames[0] = "Gabriel";
	this->_randomNames[1] = "Rick";
	this->_randomNames[2] = "Carl";
	this->_randomNames[3] = "Daryl";
	this->_randomNames[4] = "Carole";
}
