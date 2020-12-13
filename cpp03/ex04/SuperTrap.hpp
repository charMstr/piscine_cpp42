/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:52:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/13 18:54:47 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
//#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string name = "default");
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap &	operator=(SuperTrap const &rhs);

		//redifinition of the function in diamond, to avoid two
		//overidings, we have to define the function and make it call
		//the specific parent's func.
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, SuperTrap const &i);

#endif
