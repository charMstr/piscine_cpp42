/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:23:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 13:24:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) :	
	_inventory(NULL),
	_fullnessInventory(0)
{
	std::cout << "\033[33mconstructor called for MateriaSource\033[0m" \
		<< std::endl;
	//malloc for 4 pointers no matter what!
	_createAndInitInventory();
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "\033[33mdestructor called for MateriaSource\033[0m" \
		<< std::endl;
	_cleanInventory();
	delete _inventory;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout << "\033[33m(BY COPY)constructor called for MateriaSource\033[0m" \
		<< std::endl;
	_createAndInitInventory();
	*this = src;
	return ;
}

MateriaSource	&
MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		// make sure we clean anything we possess before in the inventory
		_cleanInventory();
		_fullnessInventory = rhs._fullnessInventory;
		for (int i = 0; i < rhs._fullnessInventory; i++)
			_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, MateriaSource const &rhs)
//{
//	o << rhs.getValue();
//	return o;
//}

void
MateriaSource::_createAndInitInventory(void)
{
	_inventory = new AMateria*[4];
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

void
MateriaSource::_cleanInventory(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)	
		delete _inventory[i];
}

void	
MateriaSource::learnMateria(AMateria *m)
{
	if (!m || _fullnessInventory == MAX_MATERIA)
		return ;
	//otherwise try to add in the first empty spot
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "MateriaSource succeffully learned " \
				<< m->getType() << " at index " << i << std::endl;
			break ;
		}
	}
	_fullnessInventory += 1;
}

AMateria*
MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _fullnessInventory; i++)
	{
		if (type == _inventory[i]->getType())
		{
			return (_inventory[i]->clone());
		}
	}
	return (NULL);
}
