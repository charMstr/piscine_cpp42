/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:52:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 06:43:46 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"
# include <time.h>
# include <stdlib.h>

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void 	setZombieType(std::string type);
		Zombie	*newZombie(std::string name);
		Zombie 	*randomChump(void);
		void 	announce(std::string name);
	
	private:
		void	initRandomNames(void);
		std::string _type;
		std::string _randomNames[5];
};

#endif
