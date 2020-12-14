/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:48 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 09:18:58 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string name = "\"default_peon\"");
virtual	~Peon(void);
		Peon(Peon const &src);

		Peon &	operator=(Peon const &rhs);

		virtual void		getPolymorphed() const;
	protected:

	private:
};

//already overloaded in BASE CLASS Victim
//std::ostream	&operator<<(std::ostream &o, Peon const &i);

#endif
