/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:45:39 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 19:39:08 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

//#include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
virtual	~TacticalMarine(void);
		TacticalMarine(TacticalMarine const &src);
		TacticalMarine &	operator=(TacticalMarine const &rhs);

		virtual			ISpaceMarine* clone() const;
		virtual void	battleCry() const;
		virtual void	rangedAttack() const;
		virtual void	meleeAttack() const;

	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, TacticalMarine const &i);

#endif
