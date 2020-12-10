/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:09:27 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 08:00:03 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
# include <iostream>
# include <time.h>
# include <stdlib.h>

class ZombieHorde
{
	public:
		ZombieHorde(int size);
		~ZombieHorde(void);

		void 	announce(void) const;

	private:
		void 		initRandomNames(void);
		std::string getRandomName(void) const;

		int _sizeHorde;
		std::string _randomNames[5];
		Zombie *_Horde;
};

#endif
