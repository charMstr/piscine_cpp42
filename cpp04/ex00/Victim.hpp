/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 07:09:13 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/14 10:10:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	public:
		Victim(std::string name = "\"default_victime\"");
		Victim(Victim const &src);
virtual	~Victim(void);

		Victim &	operator=(Victim const &rhs);

		std::string	const 	getName() const;

		virtual void		getPolymorphed() const;

	protected:

		std::string	_name;
	private:
};

//not made virtual because it wont be redifined by the child classes
std::ostream	&operator<<(std::ostream &o, Victim const &i);

#endif
