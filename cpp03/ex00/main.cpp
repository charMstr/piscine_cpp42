/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:00:40 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 07:03:53 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	FragTrap Robot1("robot1");
	FragTrap Robot2 ("robot2");
	FragTrap AnonymousRobot;

	int i = 1;
	while (i)
	{
		//attack robot2 until he is "dead", robots dont die.
		Robot1.rangedAttack("robot2");
		i = Robot2.takeDamage(Robot1.getRangeAttackDammage());
	}
	//repair robot.
	Robot2.beRepaired(50);
	//reattack him once with meleeattack
	Robot1.meleeAttack("robot2");
	Robot2.takeDamage(Robot1.getMeleeAttackDammage());

	while (Robot2.vaulthunter_dot_exe("robot1"))
		;
	return (0);
}
