/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:38:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 22:26:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"

Squad::Squad(void) :
	_headSquad(NULL),
	_totalUnit(0)
{
	std::cout << "\033[33mA squad constructor is called\033[m" << std::endl;
	return ;
}

Squad::~Squad(void)
{
	std::cout << "\033[33mA squad destructor is called\033[m" << std::endl;
	cleanSquadList();
	return ;
}

/*
** note:	this function is called whenever the linked list will need to be
** destoyed
*/
void
Squad::cleanSquadList(void)
{
	SquadList	*current = _headSquad;
	SquadList	*previous;
	for (int i = 0; i < getCount() ; i++)
	{
		previous = current;
		current = current->next;
		delete previous->data;
		delete previous;
	}
	return ;
}

/*
** note:	We only get here when initializing, not when just using the '='
** 			operator, Therefor we can know if the list we are copying already
** 			has some data in it!
*/
Squad::Squad(Squad const &src) :
	_headSquad(NULL),
	_totalUnit(0)
{	
	//rule of thumb: it contains pointers/malloc, so we have to malloc as well
	*this = src;
	return ;
}

Squad	&
Squad::operator=(Squad const &rhs)
{
	ISpaceMarine *new_recruit;

	if (this == &rhs) //OK
		return *this;
	//first check if we wont overide an existing Squad.
	if (_totalUnit)
		cleanSquadList();
	_totalUnit = 0;
	_headSquad = NULL;
	SquadList *tmp = rhs._headSquad;
	while (tmp)
	{
		if ((new_recruit = tmp->data->clone()) == NULL)
		{
			cleanSquadList();
			return (*this);
		}
		push(new_recruit);
		tmp = tmp->next;
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, Squad const &i)
//{
//	o << rhs.getValue();
//	return o;
//}


int
Squad::getCount() const
{	
	return (_totalUnit);
}

ISpaceMarine*
Squad::getUnit(int index) const
{	
	SquadList *tmp;
	if (index >= _totalUnit || index < 0)
		return (NULL);
	tmp = _headSquad;
	for (int i = 0; i < index ; i ++)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}

int
Squad::push(ISpaceMarine *data)
{
	if (!data)
		return (1);
	SquadList *link = new SquadList;
	if (!link)
		return (0);
	link->data = data;
	link->next = NULL;
	if (!_headSquad)
	{
		_headSquad = link;
		std::cout << "\033[32mFirst Recruit!\033[m" << std::endl;
		_totalUnit += 1;
		return (1);
	}
	SquadList *tmp = _headSquad;
	while (tmp->next && tmp->data != data)
		tmp = tmp->next;
	//making sure we are not trying to add twice the same unit to the squad
	if (tmp->data == data)
	{
		std::cout << "\033[31mCant add a Unit already in the Squad!\033[m"\
			<< std::endl;
		delete link;
		return (0);
	}
	tmp->next = link;
	std::cout << "\033[32mNew recruit!\033[m" << std::endl;
	_totalUnit += 1;
	return (1);
}
