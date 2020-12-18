/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:45:29 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 09:51:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <iostream>

class Dummy
{
	public:
		Dummy(int i);
virtual	~Dummy(void);
		Dummy(Dummy const &src);
		Dummy &	operator=(Dummy const &rhs);

	//function to serialize my output from the << overload
		virtual std::ostream & Serialize(std::ostream &o) const;

		bool operator==(Dummy const &rhs) const;
		bool operator<(Dummy const &rhs) const;
		bool operator>(Dummy const &rhs) const;
	protected:

	private:
		int	_i;
		
};

std::ostream	&operator<<(std::ostream &o, Dummy const &rhs);

#endif
