/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:06:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 12:11:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string name = "anonymous");
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap &	operator=(NinjaTrap const &rhs);

		//specialisation of functions
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;

		//same signature, but different class parameter.
		void ninjaShoebox(NinjaTrap &inst) const;
		void ninjaShoebox(ClapTrap &inst) const;
		void ninjaShoebox(FragTrap &inst) const;
		void ninjaShoebox(ScavTrap &inst) const;
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, NinjaTrap const &i);

#endif
