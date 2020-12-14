/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:00:40 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:28:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <ctime>
#include <cstdlib>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::srand(std::time(NULL)); // use current time as seed for random generator

	NinjaTrap NinjaVictim("ninja_victim");

	std::cout << std::endl << std::endl;

	//test 1
	std::cout << "\033[32mTest 1: Creating a SUPER-TRAP" << std::endl\
		<< "making sure there is only one CL4P-TRAP created...\033[m" << std::endl;
	SuperTrap Super1("maurice");

	std::cout << std::endl << std::endl;

	//test 2
	std::cout << "\033[32mTest 2: using SUPER-TRAP's base class Methods." << std::endl\
		<< "	A) method coming only from parent ninja:\033[m" << std::endl;
	Super1.ninjaShoebox(NinjaVictim);

	std::cout << "\033[32m	B) method coming only from parent FR4G-TRAP:\033[m" << std::endl;
	Super1.vaulthunter_dot_exe("SoMeOne");	

	std::cout << "\033[32m	C) method coming from both: rangeAttack from FR4G-TRAP\033[m" << std::endl;
	Super1.rangedAttack("Victim");

	std::cout << "\033[32m	D) method coming from both: meleeAttack from NINJ4-TRAP\033[m" << std::endl;
	Super1.meleeAttack("Victim");

	std::cout << std::endl << std::endl;

	return (0);
}
