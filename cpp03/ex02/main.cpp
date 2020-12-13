/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:00:40 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:25:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ctime>
#include <cstdlib>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::srand(std::time(NULL)); // use current time as seed for random generator
	std::cout << "\033[31mTest 1: ClapTrap instantiation\033[m" << std::endl;

	//contructing a ClapTrap
	//		1) calling the clapTrap constructor.
	{
		ClapTrap Robot2("Clap-Master");
	}

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 2: FragTrap instantiation\033[m" << std::endl;
	//contructing a FragTrap
	//		1) calling the Clap-Trap constructor (Parent class)
	//		2)calling the the Frag-Trap (Child Class).
	{
		FragTrap Robot1("Frag-Arthur");
	}

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 3: ScavTrap instantiation\033[m" << std::endl;
	//construction a ScavTrap
	//		1) calling the Clap-Trap constructor (Parent class)
	//		2)calling the the Scav-Trap (Child Class).
	{
		ScavTrap Robot1("Scav-Antonio");
	}

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 4: instantiation of a Frap-Trap" << std::endl \
		<< "	then a Clap-Trap copying the Frag-Trap\033[m" << std::endl;
	//construction a ScavTrap
	//		1) calling the Clap-Trap constructor (Parent class)
	//		2) calling the Frag-Trap constructor (child class)
	//		3) calling the Clap-trap constructor by copy(with a Frag-Trap which
	//			is also a Clap-Trap so its ok).
	{
		FragTrap Robot1("...Frap-Trap_to_copy_into_a_Clap-Trap...");
		ClapTrap Robot2(Robot1);
	}

	std::cout << std::endl << std::endl;

	std::cout << "\033[31mTest 5: instantiation of a Frap-Trap" << std::endl \
		<< "	then a Frap-Trap copying the Frag-Trap\033[m" << std::endl;
	//construction a ScavTrap
	//		1) calling the Clap-Trap constructor (Parent class)
	//		2) calling the Frag-Trap constructor (child class)
	//
	//		3) calling the Clap-trap constructor by copy(with a Frag-Trap which
	//			is also a Clap-Trap so its ok).
	//		4) calling the Frag-trap constructor by copy
	{
		FragTrap Robot1("...Frap-Trap_to_copy_into_another_Frag-Trap...");
		FragTrap Robot2(Robot1);
	}

	std::cout << std::endl << std::endl;
	std::cout << "\033[31mTest 5: some attacks from our ScavTrap\033[m" << std::endl;

	ScavTrap scavMan("scavMan");

	scavMan.rangedAttack("Victim");
	return (0);
}
