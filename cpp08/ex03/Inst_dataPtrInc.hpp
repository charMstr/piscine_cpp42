/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_dataPtrInc.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:04:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:05:13 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_DATAPTRINC_HPP
# define INST_DATAPTRINC_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"

class Inst_dataPtrInc : public Instructions
{
	public:
		virtual ~Inst_dataPtrInc(void) {}
		virtual void execute(MindOpen &ref)
		{
			++(ref.get_dataPtr());
		}
};

#endif
