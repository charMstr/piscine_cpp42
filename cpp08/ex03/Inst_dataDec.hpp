/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_dataDec.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:10:49 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:11:16 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_DATADEC_HPP
# define INST_DATADEC_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"

class Inst_dataDec : public Instructions
{
	public:
		virtual ~Inst_dataDec(void) {}
		virtual void execute(MindOpen &ref)
		{
			--(*(ref.get_dataPtr()));
		}
};

#endif
