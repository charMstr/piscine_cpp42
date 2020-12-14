/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:25:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 11:26:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

//#include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &src);
virtual	~SuperMutant(void);

		SuperMutant &	operator=(SuperMutant const &rhs);

		virtual void	takeDamage(int d);
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, SuperMutant const &i);

#endif
