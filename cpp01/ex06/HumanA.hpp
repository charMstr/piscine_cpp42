/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:19:21 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 06:48:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		~HumanA(void);
		HumanA(std::string name, Weapon& Weap);
		
		void attack(void) const;

	protected:

	private:
		std::string	_name;
		Weapon&		_Weapon;
};

#endif
