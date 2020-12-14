/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:54:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 12:16:10 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	public:
		Enemy(int hp = 0, std::string const & type = "\"defalut_enemy\"");
		Enemy(Enemy const &src);
virtual	~Enemy(void);

		Enemy &	operator=(Enemy const &rhs);

		std::string		getType() const;
		int				getHP() const;
		void			setHP(int new_hp);
		void			setType(std::string const &type);
		virtual void	takeDamage(int d);
	protected:

	private:
		int			_hp;
		std::string _type;
		
};

//std::ostream	&operator<<(std::ostream &o, Enemy const &i);

#endif
