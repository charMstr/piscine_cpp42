/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:26:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 18:32:39 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

//#include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const &src);
virtual	~AssaultTerminator(void);

		AssaultTerminator &	operator=(AssaultTerminator const &rhs);

		virtual			ISpaceMarine* clone() const;
		virtual void	battleCry() const;
		virtual void	rangedAttack() const;
		virtual void	meleeAttack() const;
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, AssaultTerminator const &i);

#endif
