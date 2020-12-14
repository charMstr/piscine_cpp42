/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:05:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 11:22:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	public:
		AWeapon(std::string const &name = "\"default\"", int apcost = 0,\
				int damage = 0);
		AWeapon(AWeapon const &src);
virtual	~AWeapon(void);
		AWeapon &	operator=(AWeapon const &rhs);

		std::string 			getName() const;
		int						getAPCost() const;
		int						getDamage() const;
		//this makes its an abstract class with a PUV func.
		virtual void			attack() const = 0;

	protected:
		std::string	_name;
		int			_apcost;
		int			_damage;

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, AWeapon const &i);

#endif
