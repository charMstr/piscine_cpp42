/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:23:59 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 12:30:56 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	Human Marley = Human("Marley");

	Marley.action("meleeAttack", "Jhonny");
	Marley.action("rangedAttack", "Sandy");
	Marley.action("intimidatingShout", "Victor");
	return (0);
}
