/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:39:42 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 22:24:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* GIVEN TEST" \
		" **************\033[m" << std::endl << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}

	std::cout << std::endl << "\033[35m************************* MY TEST" \
		" **************" << std::endl;
	std::cout << std::endl << "\033[35mTEST 1): empty squad\033[m"\
		<< std::endl;
	{
		Squad Bataillion;
		std::cout << Bataillion.getCount() << std::endl;
		std::cout << Bataillion.getUnit(-1) << std::endl;
		std::cout << Bataillion.getUnit(0) << std::endl;
		std::cout << Bataillion.getUnit(1) << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 2): adding to squad 1 recruit\033[m"\
		<< std::endl;
	{
		Squad Bataillion;
		ISpaceMarine *boby = new TacticalMarine;
		Bataillion.push(boby);
	}
	std::cout << std::endl << "\033[35mTEST 3): adding to squad clone recruits only\033[m"\
		<< std::endl;
	{
		Squad Bataillion;
		ISpaceMarine *jhonny = new AssaultTerminator;
		Bataillion.push(jhonny->clone());
		Bataillion.push(jhonny->clone());
		Bataillion.push(jhonny->clone());
		Bataillion.push(jhonny->clone());
		std::cout << std::endl;
		delete jhonny;
	}
	std::cout << std::endl << "\033[35mTEST 4): adding to a squad twice the" \
		" same unit, or NULL\033[m" << std::endl;
	{
		Squad Bataillion;
		ISpaceMarine *jhonny = new AssaultTerminator;
		Bataillion.push(jhonny);
		Bataillion.push(jhonny);
		Bataillion.push(jhonny->clone());
		Bataillion.push(NULL);
		std::cout << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 5): creating a squad by copy" \
		"\033[m" << std::endl;
	{
		ISpaceMarine *jhonny = new AssaultTerminator;
		Squad Bataillion1;
		Bataillion1.push(jhonny->clone());
		Bataillion1.push(jhonny->clone());
		Squad Bataillion2 = Bataillion1;
		std::cout << std::endl;
		delete jhonny;
	}
	std::cout << std::endl << "\033[35mTEST 6): copying a squad into another" \
		" squad that already had data in it... no LEAKS!\033[m" << std::endl;
	{
		ISpaceMarine *jhonny = new AssaultTerminator;
		Squad Bataillion1;
		Squad Bataillion2;
		Bataillion1.push(jhonny->clone());
		Bataillion2.push(jhonny->clone());
		Bataillion2 = Bataillion1;
		std::cout << std::endl;
		delete jhonny;
	}
	return (0);
}
