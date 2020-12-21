/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_dataPrint.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:17:29 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:47:37 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_DATAPRINT_HPP
# define INST_DATAPRINT_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"
# include <iostream>

class Inst_dataPrint : public Instructions
{
	public:
		virtual ~Inst_dataPrint(void) {}
		virtual void execute(MindOpen &ref)
		{
			std::cout << *(ref.get_dataPtr());
		}
};

#endif
