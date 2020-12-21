/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_dataPtrDec.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:07:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:08:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_DATAPTRDEC_HPP
# define INST_DATAPTRDEC_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"

class Inst_dataPtrDec : public Instructions
{
	public:
		virtual ~Inst_dataPtrDec(void) {}
		virtual void execute(MindOpen &ref)
		{
			--(ref.get_dataPtr());
		}
};

#endif
