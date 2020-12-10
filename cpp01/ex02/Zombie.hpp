/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:19:50 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 05:31:10 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name, std::string type);
		~Zombie(void);

		void advert(void);

	private:
		std::string _name;
		std::string _type;
};

#endif
