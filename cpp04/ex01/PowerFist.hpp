/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:49:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 10:51:19 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

//#include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist(void);
		PowerFist(PowerFist const &src);
virtual	~PowerFist(void);
		PowerFist &	operator=(PowerFist const &rhs);
		void			attack() const;

	protected:

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, PowerFist const &i);

#endif
