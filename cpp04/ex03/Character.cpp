/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:20:30 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 13:24:19 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(std::string const &name):
	_name(name),
	_inventory(NULL),
	_fullnessInventory(0)
{
	std::cout << "\033[33mconstructor called for Character (" << getName() \
		<< ")\033[0m" << std::endl;
	//malloc for 4 pointers no matter what!
	_createAndInitInventory();
	return ;
}

Character::~Character(void)
{
	std::cout << "\033[33mdestructor called for Character (" << getName() \
		<< ")\033[0m" << std::endl;
	//destroy the malloc array of 4 pointers to amateria
	_cleanInventory();
	delete _inventory;
	return ;
}

Character::Character(Character const &src)
{
	std::cout << "\033[33m(BY COPY) constructor called for Character" \
		" \"yet_to_be_named\" \033[0m" << std::endl;
	_createAndInitInventory();
	//note: we only got here if we instanciate by copy.
	//	Then: deep copy.
	*this = src;
	return ;
}

Character	&
Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		//make sure we clean whatever is inside the current inventory
		_cleanInventory();
		_fullnessInventory = rhs._fullnessInventory;
		this->_name = rhs._name;
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			//we create a deep copy
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, Character const &rhs)
//{
//	o << rhs.getValue();
//	return o;
//}

void
Character::_createAndInitInventory(void)
{
	_inventory = new AMateria*[4];
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

void
Character::_cleanInventory(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)	
		delete _inventory[i];
}

std::string const &
Character::getName() const
{
	return (_name);
}

void
Character::equip(AMateria* m)
{
	if (!m || _fullnessInventory == MAX_MATERIA)
		return ;
	//otherwise try to add in the first empty spot
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << getName() << " succeffully equiped with " \
				<< m->getType() << " at index " << i << std::endl;
			break ;
		}
	}
	_fullnessInventory += 1;
}
void

Character::unequip(int idx)
{		
	if (_fullnessInventory == 0 || idx >= MAX_MATERIA || idx < 0)
		return ;
	if (_inventory[idx])
	{
		std::cout << getName() << " succeffully unequiped " \
			<< (_inventory[idx])->getType() << " at index: " << idx \
			<< std::endl;
		_fullnessInventory -= 1;	
		_inventory[idx] = NULL;
	}
}

void
Character::use(int idx, ICharacter& target)
{
	//note: cannot use AMateria on yourself
	if (idx >= MAX_MATERIA || idx < 0)
		return ;
	if  (&target == this)
	{
		std::cout << "You cant use AMateria on yourself!" << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
