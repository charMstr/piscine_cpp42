/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:26:49 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 07:57:18 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	ZombieHorde 	HordeCreator(10);

	HordeCreator.announce();

	std::cout <<  std::endl;

	return (0);
}
