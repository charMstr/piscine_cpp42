/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:05:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 13:10:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"
//#include <iostream>

class RadScorpion : public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &src);
virtual	~RadScorpion(void);

		RadScorpion &	operator=(RadScorpion const &rhs);

		//only the constructor/destructor needed to be overidden
//		virtual void	takeDamage(int d);
	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, RadScorpion const &i);

#endif
