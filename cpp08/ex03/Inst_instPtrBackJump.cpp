/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_instPtrBackJump.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:42:53 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:37:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Inst_instPtrBackJump.hpp"
#include "Inst_instPtrFwdJump.hpp"
# include "MindOpen.hpp"

/*
** we get here when we met a ']' instruction, basically it represents the end
** of a while loop. two cases:
** - the currently pointed data is non zero --> we move back to the begining of
** while ('['), the process() func in the main loop, will increase the
** instruction pointer onto the first while instruction.
** - the currently pointed data is zero, do nothing, the instruction pointer
** will be moved to the next instrucion after the while in process() func.
*/

#include <iostream>
void
Inst_instPtrBackJump::execute(MindOpen &ref)
{
	int close(1);
	if (!(*ref.get_dataPtr())) //if the pointed data is zero
		return ;
	//note: we know anyway that the begin would be at least a '[' sign
	while (ref.dec_instPtr())
	{
		//means we met another ']' on the way.
		if (dynamic_cast<Inst_instPtrBackJump*>(*ref.get_instPtr()))
		{	
			close++;	
		}
	 	if (dynamic_cast<Inst_instPtrFwdJump*>(*ref.get_instPtr()))
		{
			close--;
			if (close == 0)
			{
				return ;
			}
		}
	}
	//getting here means we got to the very first '[', OK
}
