/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:46 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 12:17:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>


//default
Fixed::Fixed(void) :
	_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

//copy constructor
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

//contstructor from an int
Fixed::Fixed(const int int_input)
{
	std::cout << "Int to Fixed constructor called" << std::endl;
	_fixedPointValue = int_input << this->_bitsNbr;
}

//contstructor from a float
Fixed::Fixed(const float int_input)
{
	std::cout << "Float to Fixed constructor called" << std::endl;
	_fixedPointValue = (int)(roundf(int_input * (1 << this->_bitsNbr)));
}

Fixed	&
Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPointValue = rhs.getRawBits();//put code here
	}
	return *this;
}

//overload of the << operator
std::ostream	&
operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

//assignation of the non member attribute.
const int Fixed::_bitsNbr = 8;

int
Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void
Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

int
Fixed::toInt(void) const
{
	return (_fixedPointValue >> 8);
}

float
Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _bitsNbr));
}
