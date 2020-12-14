/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 06:45:57 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 07:38:39 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string name = "\"default_name\"", std::string title = "\"default_title\"");
		Sorcerer(Sorcerer const &src);
virtual	~Sorcerer(void);

		Sorcerer &	operator=(Sorcerer const &rhs);

		std::string	getName() const;
		std::string	getTitle() const;

		void		polymorph(Victim const &vi);
	protected:

	private:
		std::string _name;
		std::string _title;
		
};

std::ostream	&operator<<(std::ostream &o, Sorcerer const &i);

#endif
