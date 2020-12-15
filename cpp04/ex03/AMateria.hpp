/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:37:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 09:32:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

# include "ICharacter.hpp"

//class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const & type = "\"default_type\"");
		AMateria(AMateria const &src);
		AMateria &	operator=(AMateria const &rhs);
virtual	~AMateria(void);

		std::string const &	getType() const; //Returns the materia type
		unsigned int		getXP() const; //Returns the Materia's XP
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);
	protected:
		void				incXP(int inc = 10);

	private:
		std::string		_type;
		unsigned int	_xp;
};

//std::ostream	&operator<<(std::ostream &o, AMateria const &rhs);

#endif
