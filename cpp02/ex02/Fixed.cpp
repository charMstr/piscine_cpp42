/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:46 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 12:31:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

/*
** note: check the bottom of the file for the day02/ex02.
*/

//default
Fixed::Fixed(void) :
	_fixedPointValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

//destructor
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

//copy constructor
Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

//contstructor from an int
Fixed::Fixed(const int int_input)
{
	//std::cout << "Int to Fixed constructor called" << std::endl;
	_fixedPointValue = int_input << this->_bitsNbr;
}

//contstructor from a float
Fixed::Fixed(const float int_input)
{
	//std::cout << "Float to Fixed constructor called" << std::endl;
	_fixedPointValue = (int)(roundf(int_input * (1 << this->_bitsNbr)));
}

Fixed	&
Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Assignation operator called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void
Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

int
Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
	return (_fixedPointValue >> 8);
}

float
Fixed::toFloat(void) const
{
	//std::cout << "toFloat member function called" << std::endl;
	return ((float)_fixedPointValue / (float)(1 << _bitsNbr));
}

//* ex02 **********************************************************************

//comparison operators
bool
Fixed::operator>(Fixed const &rhs) const
{
	if (_fixedPointValue > rhs.getRawBits())
		return (true);
	return (false);
}

bool
Fixed::operator<(Fixed const &rhs) const
{
	if (_fixedPointValue < rhs.getRawBits())
		return (true);
	return (false);
}

bool
Fixed::operator>=(Fixed const &rhs) const
{
	if (_fixedPointValue >= rhs.getRawBits())
		return (true);
	return (false);
}

bool
Fixed::operator<=(Fixed const &rhs) const
{
	if (_fixedPointValue <= rhs.getRawBits())
		return (true);
	return (false);
}

bool
Fixed::operator==(Fixed const &rhs) const
{
	if (_fixedPointValue == rhs.getRawBits())
		return (true);
	return (false);
}

bool
Fixed::operator!=(Fixed const &rhs) const
{
	if (_fixedPointValue != rhs.getRawBits())
		return (true);
	return (false);
}


//arithmetic operators
Fixed
Fixed::operator+(Fixed const &rhs) const
{
	Fixed tmp(this->toInt() + rhs.toInt());
	return (tmp);
}

Fixed
Fixed::operator-(Fixed const &rhs) const
{
	Fixed tmp(this->toInt() - rhs.toInt());
	return (tmp);
}

Fixed
Fixed::operator*(Fixed const &rhs) const
{
	Fixed tmp(this->toFloat() * rhs.toFloat());
	return (tmp);
}

Fixed
Fixed::operator/(Fixed const &rhs) const
{
	Fixed tmp(this->toFloat() / rhs.toFloat());
	return (tmp);
}

//var--, --var, var++, ++var
Fixed	&
Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

Fixed	
Fixed::operator++(int)
{
	Fixed tmp(*this);

	_fixedPointValue++;
	return (tmp);
}

Fixed	&
Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed	
Fixed::operator--(int)
{
	Fixed tmp(*this);

	_fixedPointValue--;
	return (tmp);
}

//last part ***********************
Fixed	&
Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	return (ref2);
}

Fixed	&
Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	return (ref2);
}

Fixed const &
Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	return (ref2);
}

Fixed const &
Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	return (ref2);
}
