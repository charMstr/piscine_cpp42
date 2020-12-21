/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_dataInc.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:09:33 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:12:57 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_DATAINC_HPP
# define INST_DATAINC_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"

class Inst_dataInc : public Instructions
{
	public:
		virtual ~Inst_dataInc(void) {}
		virtual void execute(MindOpen &ref)
		{
			++(*(ref.get_dataPtr()));
		}
};

#endif
