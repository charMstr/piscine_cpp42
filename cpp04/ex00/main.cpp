/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 06:45:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 09:39:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << "\033[35m*********************** TESTS PROVIDED********************\033[m" << std::endl << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}

	std::cout << std::endl << std::endl;

	std::cout << "\033[35m******************* MY ADDITIONAL TESTS *****************\033[m" << std::endl;
	//test1
	std::cout << std::endl << "\033[35mTEST1: building a Sorcerer by copy, and overload of '='\033[m" << std::endl;
	{
		Sorcerer	Wizzard("kevin", "Wizzard");
		Sorcerer	CopyWizzard(Wizzard);
		Sorcerer	WillChangeSOon("SOON_TO_BECHANGED", "Black Magician");
		WillChangeSOon = Wizzard;
		std::cout << "\033[33mnote: SOON_TO_BE CHANGED should now be: kevin wizzard\033[0m" << std::endl;
	}

	//test2
	std::cout << std::endl << "\033[35mTEST2: building a victim by copy, and overload of '='\033[m" << std::endl;
	{
		Victim 	Victim1("kevin");
		Victim	CopyVictim(Victim1);
		Victim WillChangeSOon("SOON_TO_BECHANGED");
		WillChangeSOon = Victim1;
		std::cout << "\033[33mnote: SOON_TO_BE CHANGED should now be: kevin\033[0m" << std::endl;
	}

	//test3
	std::cout << std::endl << "\033[35mTEST3: building a Peon by copy, and overload of '='\033[m" << std::endl;
	{
		Peon 	Peon1("kevin");
		Peon	CopyVictim(Peon1);
		Peon WillChangeSOon("SOON_TO_BECHANGED");
		WillChangeSOon = Peon1;
		std::cout << "\033[33mnote: SOON_TO_BE CHANGED should now be: kevin\033[0m" << std::endl;
	}

	//test4
	std::cout << std::endl << "\033[35mTEST4: dereferencing a pointer of type victim, but pointing to a peon\033[m" << std::endl;
	{
		Victim *vic_pointer = new Peon("antonio-PEON");
		vic_pointer->getPolymorphed();
	}

	//test5
	std::cout << std::endl << "\033[35mTEST5: dereferencing a pointer of type victim, but pointing to a victim\033[m" << std::endl;
	{
		Victim *vic_pointer = new Victim("antonio-victim");
		vic_pointer->getPolymorphed();
	}
	return (0);
}
