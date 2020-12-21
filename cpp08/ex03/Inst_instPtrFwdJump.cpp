/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inst_instPtrFwdJump.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:45:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 09:30:46 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MindOpen.hpp"
# include "Inst_instPtrBackJump.hpp"
# include "Inst_instPtrFwdJump.hpp"

/*
** we get here when we met a '[' instruction, basically it represents the start
** of a while loop. two cases:
** - the currently pointed data is zero --> we move to the end of while, and in
** the process() func main loop the instruction pointer willl be moved to the
** instrucion right after.
** - the currently pointed data is non zero, enter the while.
*/

void
Inst_instPtrFwdJump::execute(MindOpen &ref)
{
	int open(1);
	if (*ref.get_dataPtr())
		return;
	//otherwise, jump to matching ']'
	while (ref.inc_instPtr())
	{
		//means we met another '[' on the way.
		if (dynamic_cast<Inst_instPtrFwdJump*>(*ref.get_instPtr()))
			open++;
		else if (dynamic_cast<Inst_instPtrBackJump*>(*ref.get_instPtr()))	
		{
			open--;
			if (open == 0)
				break; //leave the pointer on the matching ']', it will be
						//incremented in the process() func loop.
		}
	}
}
