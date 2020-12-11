/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:10:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 06:29:05 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(void);
		~Weapon(void);
		Weapon(std::string type);

		std::string const	&getType(void) const;
		void				setType(std::string type);

	protected:

	private:
		std::string _type;	
};

#endif
