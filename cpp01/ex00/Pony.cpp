/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:24:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 18:32:56 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
	return ;
}

Pony::Pony(std::string name, std::string color, std::string food, \
		std::string speed) :
	_name(name),
	_favoriteFood(food),
	_color(color),
	_maxSpeed(speed)
{
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Destructor called for Pony: " << this->_name << std::endl;	
}

void Pony::eat(void)
{
	std::cout << this->_name << " is eating " << this->_favoriteFood \
		<< "." << std::endl;
}

void 
Pony::run(void)
{
	std::cout << this->_name << " is running at " << this->_maxSpeed;
	std::cout << "!" << std::endl;
}

void 
Pony::introduceSelf(void)
{
	std::cout << "Hi my name is "<< this->_name;
	std::cout << ", my color is " << this->_color;
	std::cout << " and i like to eat " << this->_favoriteFood;
	std::cout << "." << std::endl;
}

std::string
Pony::getName(void)
{
	return (this->_name);
}

std::string
Pony::getSpeed(void)
{
	return (this->_maxSpeed);
}

std::string
Pony::getFavoriteFood(void)
{
	return (this->_favoriteFood);
}

std::string
Pony::getColor(void)
{
	return (this->_color);
}
