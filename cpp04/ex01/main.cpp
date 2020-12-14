/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:05:25 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 17:18:15 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
//#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
	std::cout << std::endl << "\033[35m************************* GIVEN TEST" \
		" **************" << std::endl << std::endl;
	{
		Character* moi = new Character("moi");
		std::cout << *moi;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		moi->equip(pr);
		std::cout << *moi;
		moi->equip(pf);
		moi->attack(b);
		std::cout << *moi;
		moi->equip(pr);
		std::cout << *moi;
		moi->attack(b);
		std::cout << *moi;
		moi->attack(b);
		std::cout << *moi;
		delete pr;
		delete pf;
		delete moi;
	}

	std::cout << std::endl << "\033[35m************************* MY TEST" \
		" **************" << std::endl << std::endl;
	std::cout << std::endl << "\033[35mTEST 1) instanciating a weapon" \
		"by copy\033[m" << std::endl;
	{
		PlasmaRifle Wep1;
		PlasmaRifle Wep2(Wep1);
	}
	std::cout << std::endl << "\033[35mTEST 2) instanciate enemy and make him die" \
		"by copy\033[m" << std::endl;
	{
		Enemy Enemy1(100, "wicked bastard");
		Enemy1.takeDamage(12);
		Enemy1.takeDamage(50);
		Enemy1.takeDamage(90);
	}
	std::cout << std::endl << "\033[35mTEST 3) instanciate Mutant , and by copy" \
		"by copy\033[m" << std::endl;
	{
		SuperMutant Mut1;
		Mut1.takeDamage(10);
		SuperMutant Mut2;
		std::cout << Mut2.getHP() << std::endl;
		Mut2 = Mut1;
		std::cout << Mut2.getHP() << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 4) Smash damons until no more AP\033[m" << std::endl;
	std::cout << std::endl << std::endl;
	{
		RadScorpion Scorp;
		SuperMutant Mut1;
		PlasmaRifle Wep1;
		Character Perso1("name");
		Perso1.attack(&Scorp);
		Perso1.equip(&Wep1);
		Perso1.attack(&Scorp);
		Perso1.attack(&Scorp);
		Perso1.attack(&Scorp);
		Perso1.attack(&Mut1);
		Perso1.attack(&Mut1);
		Perso1.attack(&Mut1);
		Perso1.attack(&Mut1);
		//std::cout << Perso1 << std::endl;
		//Perso1.recoverAP();
		std::cout << Perso1;
		Perso1.attack(&Mut1);
		std::cout << Perso1;
		std::cout << "\033[31m HERE\033[m" << std::endl;
		Perso1.attack(&Mut1);
		Perso1.recoverAP();
	}
	return (0);
}
