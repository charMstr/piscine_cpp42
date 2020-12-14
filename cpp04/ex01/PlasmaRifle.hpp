/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:22:45 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 10:37:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle :  public AWeapon
{
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &src);
virtual	~PlasmaRifle(void);
		PlasmaRifle &	operator=(PlasmaRifle const &rhs);

		void			attack() const;

	protected:

	private:	

};

//std::ostream	&operator<<(std::ostream &o, PlasmaRifle const &i);

#endif
