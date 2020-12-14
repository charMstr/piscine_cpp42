/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:40:04 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 17:49:15 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

//#include <iostream>

class ISpaceMarine
{
	public:
		virtual			~ISpaceMarine() {}
		virtual			ISpaceMarine* clone() const = 0;
		virtual void	battleCry() const = 0;
		virtual void	rangedAttack() const = 0;
		virtual void	meleeAttack() const = 0;
};

//std::ostream	&operator<<(std::ostream &o, ISpaceMarine const &i);

#endif
