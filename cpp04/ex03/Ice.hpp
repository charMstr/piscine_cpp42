/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:55:59 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 10:49:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

//#include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//class ICharacter;

class Ice : public AMateria
{
	public:
		Ice(void);
virtual	~Ice(void);
		Ice(Ice const &src);
		Ice &	operator=(Ice const &rhs);

		virtual AMateria*	clone() const;
		void use(ICharacter &target);
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, Ice const &rhs);

#endif
