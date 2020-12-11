/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:24:14 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 12:28:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class Human
{
	typedef void (Human::*func)(std::string const &);

	private:
		void meleeAttack(std::string const & target);
		void rangedAttack(std::string const & target);
		void intimidatingShout(std::string const & target);

		std::string	_name;
		func		_arrayFuncPtr[3];
		std::string	_arrayFuncName[3];

	public:
		void action(std::string const & action_name, std::string const & target);

		Human(std::string name);
		~Human(void);
};

#endif
