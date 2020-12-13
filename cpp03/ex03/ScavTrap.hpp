/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:07:25 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 08:34:19 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name = "anonymous");
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const &rhs);

		//added functions:
		int		challengeNewcomer(std::string const & target);

	protected:

	private:
		//array containing the random string for attacks names.
		std::string	_attackRandom[5];
};

//std::ostream	&operator<<(std::ostream &o, ScavTrap const &i);

#endif
