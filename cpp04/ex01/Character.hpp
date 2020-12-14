/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:12:41 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 15:48:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const & name = "\"default_character\"");
		Character(Character const &src);
virtual	~Character(void);

		Character &	operator=(Character const &rhs);

		void 				recoverAP();
		void 				equip(AWeapon *weapon);
		void 				attack(Enemy *target);
		std::string const	getName() const;
		void				setName(std::string const &name);
		void				setAP(int ap);
		int					getAP(void) const;
		AWeapon	const		*getWeapon(void) const;

	protected:
		std::string	_name;
		int			_aP;
		AWeapon		*_weapon;

	private:
		
};

std::ostream	&operator<<(std::ostream &o, Character const &i);

#endif
