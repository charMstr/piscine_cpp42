/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 07:07:25 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 07:16:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
	public:
		ScavTrap(std::string name = "anonymous");
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const &rhs);

		//added functions:
		int		getMeleeAttackDammage() const;
		int		getRangeAttackDammage() const;

		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
		int		takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		int		challengeNewcomer(std::string const & target);

	protected:

	private:
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		std::string _name;
		int			_meleeAttackDamage;
		int			_rangeAttackDamage;
		int			_armorDamageReduction;

		//array containing the random string for attacks names.
		std::string	_attackRandom[5];
};

//std::ostream	&operator<<(std::ostream &o, ScavTrap const &i);

#endif
