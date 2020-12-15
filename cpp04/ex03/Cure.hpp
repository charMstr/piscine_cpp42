/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:50:47 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 10:48:59 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

//#include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//class ICharacter;

class Cure : public AMateria
{
	public:
		Cure(void);
virtual	~Cure(void);
		Cure(Cure const &src);
		Cure &	operator=(Cure const &rhs);

		virtual			AMateria*	clone() const;
		void	use(ICharacter &target);
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, Cure const &rhs);

#endif
