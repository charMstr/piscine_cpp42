/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:20:30 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/15 12:09:46 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include	<iostream>
# include	"ICharacter.hpp"
# include	"AMateria.hpp"
# define	MAX_MATERIA 4

//class AMateria;

class Character : public ICharacter
{
	public:
		Character(std::string const &name = "\"default_name\"");
virtual	~Character(void);
		Character(Character const &src);
		Character &	operator=(Character const &rhs);

		virtual std::string const &	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
	protected:
		std::string	_name;
		AMateria	**_inventory;
		int			_fullnessInventory;
		void		_createAndInitInventory(void);
		void		_cleanInventory(void);
	
	private:
			
};

//std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif
