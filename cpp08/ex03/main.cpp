/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:24:04 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:43:55 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"
#include <fstream>
#include <iostream>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::cout << std::endl << "\033[35m************************* MY TESTS" \
		" ON MINDOPEN *******" << std::endl;
	//TEST 1)
	std::cout << std::endl << "\033[35mTEST 1) "
		"easy file, with just one loop \033[m" \
		<< std::endl;
	{
		std::ifstream ifs ("MindOpen1.txt", std::ifstream::in);

		MindOpen machine(ifs);
		machine.debug_instructions();
		std::cout << std::endl << "Data initlially (30 first bytes):" << std::endl;
		machine.debug_data();
		machine.process(NO_DEBUG);
		std::cout << "Data after (30 first bytes):" << std::endl;
		machine.debug_data();
		ifs.close();
	}
	//TEST 2)
	std::cout << std::endl << "\033[35mTEST 2) "
		"HELLO WORLD! \033[m" \
		<< std::endl;
	{
		std::ifstream ifs ("MindOpen2.txt", std::ifstream::in);

		MindOpen machine(ifs);
		machine.debug_instructions();
		std::cout << std::endl << "Data initlially (30 first bytes):" << std::endl;
		machine.debug_data();
		machine.process(NO_DEBUG);
		std::cout << "Data after (30 first bytes):" << std::endl;
		machine.debug_data();
		ifs.close();
	}
	return (0);
}
