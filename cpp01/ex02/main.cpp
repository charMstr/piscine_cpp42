/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:26:49 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 07:03:23 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void createZombiesOnStack(void)
{
	//instantiating two Zombie objects.
	Zombie	William = Zombie("William", "Slow-Walker");
	Zombie	Edmund = Zombie("Edmund", "Fast-Walker");

	William.advert();
	Edmund.advert();
}

void createZombieOnHeap(std::string name)
{
	//instanciating a ZombieEvent Object.
	ZombieEvent ZombieCreator;

	//using new in setZombieType.
	ZombieCreator.setZombieType("Super-Fast-Walker");
	Zombie *createdOnHeap = ZombieCreator.newZombie(name);
	createdOnHeap->advert();

	delete createdOnHeap;
}

Zombie *createZombieInSubFunction(void)
{
	//instanciating a ZombieEvent Object.
	ZombieEvent ZombieCreator;

	//creating with randomChump: anoucing itself!
	return (ZombieCreator.randomChump());
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	createZombiesOnStack();
	std::cout << "" << std::endl;

	createZombieOnHeap("Max");
	std::cout << "" << std::endl;
	
	Zombie *Random = createZombieInSubFunction();
	std::cout << "" << std::endl;

	Random->advert();

	//delete the Zombie object instanciated outside this scope.
	delete Random;
	return (0);
}
