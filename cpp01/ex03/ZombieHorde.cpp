/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:09:27 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 07:59:54 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

//constructor
ZombieHorde::ZombieHorde(int size) :
	_sizeHorde(size)
{
	this->_Horde = new Zombie[size];
	this->initRandomNames();
	srand (time(NULL));
	for (int i = 0; i < size; i++)
	{
		this->_Horde[i].setName(this->getRandomName());
	}
}

//destructor
ZombieHorde::~ZombieHorde(void)
{
	std::cout << "destructor called in ZombieHorde Object" << std::endl;
	
	delete[] _Horde;
}

//announce all the zombies
void 
ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_sizeHorde; i++)
	{
		this->_Horde[i].announce();
	}
}

//private functions************************************************************

void
ZombieHorde::initRandomNames(void)
{
	this->_randomNames[0] = "Gabriel";
	this->_randomNames[1] = "Rick";
	this->_randomNames[2] = "Carl";
	this->_randomNames[3] = "Daryl";
	this->_randomNames[4] = "Carole";
}

std::string
ZombieHorde::getRandomName(void) const
{	
	int	randomNumber;

	randomNumber =  rand() % 5;
	return(this->_randomNames[randomNumber]);
}
