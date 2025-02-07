/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:01:23 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 12:07:04 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name = "anonymous");
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const &rhs);
	
		//specialisation of functions
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;

		//added functions:
		int		vaulthunter_dot_exe(std::string const & target);
	protected:

	private:
		std::string	_attackRandom[5];
			
};

//std::ostream	&operator<<(std::ostream &o, FragTrap const &i);

#endif
