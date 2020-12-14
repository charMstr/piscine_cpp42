/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:45:39 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 20:39:28 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for action !" << std::endl;
	return ;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src)
{
	*this = src;
	return ;
}

TacticalMarine	&
TacticalMarine::operator=(TacticalMarine const &rhs) // NOT OK//KO
{
	if (this != &rhs)
	{
		//nothing to do so far as there is no internal variables.
		;//put code here
	}
	return *this;
}

//std::ostream	&
//operator<<(std::ostream &o, TacticalMarine const &i)
//{
//	o << rhs.getValue();
//	return o;
//}

void
TacticalMarine::rangedAttack() const //OK
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void
TacticalMarine::meleeAttack() const //OK
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

ISpaceMarine*
TacticalMarine::clone() const //OK
{
	TacticalMarine *cloned = new TacticalMarine;
	//not used so far.
	//*cloned = TacticalMarine(*this);
	return (cloned);
}

void
TacticalMarine::battleCry() const //OK
{
	std::cout << "For the Holy PLOT !" << std::endl;
}
