/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:00:40 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 09:41:53 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	std::cout << "CREATING a couple of  TRAPS" << std::endl;

	ClapTrap  RobotClap("marcus the clap");
	FragTrap  RobotFrag("jhonny the frag");
	ScavTrap  RobotScav("carol the scav");
	NinjaTrap  RobotNinjaAttacker("daryl the ninja");
	NinjaTrap  RobotNinjaVictim("other ninja victim");

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 1: NINJA ATTACKS NINJA\033[m" << std::endl;
	RobotNinjaAttacker.ninjaShoebox(RobotNinjaVictim);

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 2: NINJA ATTACKS CLAP\033[m" << std::endl;
	RobotNinjaAttacker.ninjaShoebox(RobotClap);

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 3: NINJA ATTACKS FRAG\033[m" << std::endl;
	RobotNinjaAttacker.ninjaShoebox(RobotFrag);

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 4: NINJA ATTACKS SCAV\033[m" << std::endl;
	RobotNinjaAttacker.ninjaShoebox(RobotScav);

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 5: NINJA ATTACKS HIMSELF\033[m" << std::endl;
	RobotNinjaAttacker.ninjaShoebox(RobotNinjaAttacker);

	std::cout << std::endl << std::endl;
	return (0);
}
