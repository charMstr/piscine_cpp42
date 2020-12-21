/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:18:07 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:58:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

class MindOpen;

class Instructions
{
	public:
		virtual ~Instructions(void) {}
		virtual void execute(MindOpen &ref) = 0;
};

#endif
