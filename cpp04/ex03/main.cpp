/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:36:34 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 13:45:31 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	
	std::cout << std::endl << "\033[35m************************* SUBJECT TEST" \
		" **************" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* moi = new Character("moi");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		moi->equip(tmp);
		tmp = src->createMateria("cure");
		moi->equip(tmp);
		ICharacter* bob = new Character("bob");
		moi->use(0, *bob);
		moi->use(1, *bob);
		delete bob;
		delete moi;
		delete src;
	}
	
	std::cout << std::endl << "\033[35m************************* MY TEST" \
		" **************" << std::endl;
	std::cout << std::endl << "\033[35mTEST 1): creating materia\033[m"\
		<< std::endl;
	{
		AMateria *Am1 = new Cure;
		std::cout << Am1->getType() << std::endl;
		delete Am1;
	}
	std::cout << std::endl << "\033[35mTEST 2): Creating 2 characters\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Character	Student("student");
		std::cout << Charlie.getName() << " & " << Student.getName() << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 3): Trying to attack student\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Character	Student("student");
		Charlie.use(0, Student);
		Charlie.use(-1, Student);
		Charlie.use(4, Student);
		Charlie.use(5, Student);
	}
	std::cout << std::endl << "\033[35mTEST 4): Unequiping When empty\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Charlie.unequip(0);
		Charlie.unequip(-1);
		Charlie.unequip(5);
	}
	std::cout << std::endl << "\033[35mTEST 5): Equiping many times\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Charlie.equip(new Ice);
		Charlie.equip(new Ice);
		Charlie.equip(new Ice);
		Charlie.equip(new Ice);
		Cure 			Dummy;
		Charlie.equip(&Dummy);
		Charlie.equip(&Dummy);
		std::cout << "	note to peer: not equiped more than 4 times!" << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 6): Equiping then unequiping\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Ice			AMateriaIce;
		Charlie.equip(new Ice);
		Charlie.unequip(5);
		Charlie.unequip(-1);
		Charlie.unequip(1);
		//Charlie.unequip(0);
	}
	/*
	std::cout << std::endl << "\033[35mTEST 7): Equiping 4, unequiping 1, reequiping\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Ice			AMateriaIce;
		Charlie.equip(&AMateriaIce);
		Charlie.equip(&AMateriaIce);
		Charlie.equip(&AMateriaIce);
		Charlie.equip(&AMateriaIce);
		Charlie.unequip(2);
		Charlie.unequip(2);
		std::cout << "	note to peer: can reequipe once !" << std::endl;
		Charlie.equip(&AMateriaIce);
		Charlie.unequip(2);
	}
	*/
	std::cout << std::endl << "\033[35mTEST 8) using An Amateria, then another\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Character	Victim("Victim");
		Charlie.equip(new Ice);
		Charlie.equip(new Cure);
		Charlie.equip(new Ice);
		Charlie.use(0, Victim);
		Charlie.use(1, Victim);
		Charlie.use(2, Victim);
		std::cout << std::endl; // '\n'
		Charlie.use(3, Victim);
		Charlie.use(-1, Victim);
		Charlie.use(-5, Victim);
	}
	std::cout << std::endl << "\033[35mTEST 9) Constructor by copy\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		Charlie.equip(new Ice);
		Charlie.equip(new Cure);
		Charlie.equip(new Ice);
		Character	Victim(Charlie);
		Victim.use(1, Charlie);
	}
	std::cout << std::endl << "\033[35mTEST 10) Using MateriaSource\033[m"\
		<< std::endl;
	{
		MateriaSource Source;
		Ice			AMateriaIce;
		Source.learnMateria(new Ice);
		Source.learnMateria(new Cure);
		Source.learnMateria(new Ice);
		Source.learnMateria(new Cure);
		std::cout << "	note to peer: no more materia is added" << std::endl;
		Source.learnMateria(&AMateriaIce);
	}
	std::cout << std::endl << "\033[35mTEST 11) Using MateriaSource to equip character\033[m"\
		<< std::endl;
	{
		Character	Charlie("charlie");
		MateriaSource Source;
		Source.learnMateria(new Ice);
		Source.learnMateria(new Cure);
		AMateria *todel1 = Source.createMateria("ice");
		AMateria *todel2 = Source.createMateria("Ice");
		Charlie.equip(todel1);
		Charlie.equip(todel2);
	}
	std::cout << std::endl << "\033[35mTEST 12) deep copy of MAteria source\033[m"\
		<< std::endl;
	{
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "" << std::endl;
		MateriaSource src2(*src);
		src2.learnMateria(new Ice());
		delete src;
	}
	std::cout << std::endl << "\033[35mTEST 13) deep copy of Source 2 in" \
		" Source1 \n (when Source 1 already has some Materia in it)\033[m"\
		<< std::endl;
	{
		MateriaSource src2;
		src2.learnMateria(new Ice());
		src2.learnMateria(new Cure());
		std::cout << "" << std::endl;
		MateriaSource src1;
		src1.learnMateria(new Ice());
		src1 = src2;
		std::cout << "--> OK" << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 13): copy Character2 into character1\033[m"\
		<< std::endl;
	{
		Character Girl1("girl1");
		Character Boy1("boy1");
		Boy1.equip(new Ice);
		Boy1.equip(new Cure);
		Girl1 = Boy1;
		std::cout << "-->done" << std::endl;
	}
	std::cout << std::endl << "\033[35mTEST 14): copy Character2 into "
		"character1\n (character 1 already had some things in it\033[m"\
		<< std::endl;
	{
		Character Girl1("girl1");
		Character Boy1("boy1");
		Boy1.equip(new Ice);
		Boy1.equip(new Cure);
		Girl1.equip(new Ice);
		Girl1 = Boy1;
		std::cout << "-->done" << std::endl;
	}
	return (0);
}
