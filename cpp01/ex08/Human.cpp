/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:24:13 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 12:31:15 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

Human::Human(std::string name) :
	_name(name)
{
	_arrayFuncPtr[0] = &Human::meleeAttack;
	_arrayFuncPtr[1] = &Human::rangedAttack;
	_arrayFuncPtr[2] = &Human::intimidatingShout;

	_arrayFuncName[0] = "meleeAttack";
	_arrayFuncName[1] = "rangedAttack";
	_arrayFuncName[2] = "intimidatingShout";
	return ;
}

Human::~Human(void)
{
	return ;
}

void
Human::meleeAttack(std::string const & target)
{
	std::cout << _name << " does a melleeAttack on " << target << std::endl;
}

void
Human::rangedAttack(std::string const & target)
{
	std::cout << _name << " does a rangeAttack on " << target << std::endl;
}

void
Human::intimidatingShout(std::string const & target)
{
	std::cout << _name << " does an intimidatingShout on " << target << std::endl;
}

void
Human::action(std::string const & action_name, std::string const & target)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->_arrayFuncName[i].compare(action_name) == 0)
			(this->*_arrayFuncPtr[i])(target);
	}
}
