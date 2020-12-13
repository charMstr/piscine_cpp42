/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:37:58 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 19:18:36 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name = "anonymous");
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const &rhs);

		//added functions (common to all).
		int		getMeleeAttackDammage() const;
		int		getRangeAttackDammage() const;
		const std::string &getName() const;

		//virtual so that i can specialise them in the child classes
		virtual void	rangedAttack(std::string const & target) const;
		virtual void	meleeAttack(std::string const & target) const;

		int		takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		//put _name as const to make it harder.
		const std::string _name;
		int			_meleeAttackDamage;
		int			_rangeAttackDamage;
		int			_armorDamageReduction;

	private:
};

//std::ostream	&operator<<(std::ostream &o, ClapTrap const &i);

#endif
