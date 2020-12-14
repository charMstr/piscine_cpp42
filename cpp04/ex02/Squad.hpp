/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:38:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 22:23:48 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

//#include <iostream>
# include "ISquad.hpp"

class Squad : public ISquad
{
	public:
		Squad(void);
		Squad(Squad const &src);
virtual	~Squad(void);

		Squad &	operator=(Squad const &rhs);

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int index) const;
		virtual int push(ISpaceMarine *data);

	protected:
		struct SquadList
		{
			ISpaceMarine *data;
			SquadList *next;
		};
		SquadList	*_headSquad;
		int			_totalUnit;
		void		cleanSquadList(void);
	private:		
};

//std::ostream	&operator<<(std::ostream &o, Squad const &i);

#endif
