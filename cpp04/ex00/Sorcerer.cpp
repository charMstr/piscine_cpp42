/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 06:45:57 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 09:18:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) :
	_name(name),
	_title(title)
{
	//setting the name and title to upper case.
	for (size_t i = 0; i < _name.length(); i++)
		_name[i] = toupper(_name[i]);
	for (size_t i = 0; i < _title.length(); i++)
		_title[i] = toupper(_title[i]);
	std::cout << _name << ", "<< _title << ", " << "is born!" << std::endl;
	return ;
}

Sorcerer::~Sorcerer(void)
{	
	std::cout << _name << ", "<< _title << ", " << "is dead. Consequences" \
		" will never be the same!" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	std::cout << _name << ", "<< _title << ", " << "is born!" \
		"\033[33m (by copy)\033[m" << std::endl;
	return ;
}

Sorcerer	&
Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_title = rhs._title;
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Sorcerer const &instance)
{
	o << "\033[32mI am " << instance.getName() << ", " << instance.getTitle() \
		<< ", and i like ponies!\033[m" << std::endl;
	return o;
}

std::string
Sorcerer::getName() const
{
	return (this->_name);
}

std::string
Sorcerer::getTitle() const
{
	return (this->_title);
}

void
Sorcerer::polymorph(Victim const &vi)
{
	vi.getPolymorphed();	
}
