/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:26 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 23:28:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		std::string	identify(void) const;
		const Brain &getBrain(void) const;	

	private:
		const Brain	_Brain;
		std::string	_name;
};

#endif
