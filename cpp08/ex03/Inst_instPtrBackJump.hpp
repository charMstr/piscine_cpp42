/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_instPtrBackJump.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:35:14 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 02:45:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_INSTPTRBACKJUMP_HPP
# define INST_INSTPTRBACKJUMP_HPP

# include "Instructions.hpp"
# include "MindOpen.hpp"

class Inst_instPtrFwdJump;

class Inst_instPtrBackJump : public Instructions
{
	public:
		virtual ~Inst_instPtrBackJump(void) {}
		virtual void execute(MindOpen &ref);
};

#endif
