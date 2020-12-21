/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_instPtrFwdJump.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:21:06 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:45:50 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_INSTPTRFWDJUMP_HPP
# define INST_INSTPTRFWDJUMP_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"
# include "Inst_instPtrBackJump.hpp"

class Inst_instPtrFwdJump : public Instructions
{
	public:
		virtual ~Inst_instPtrFwdJump(void) {}
		virtual void execute(MindOpen &ref);
};

#endif
