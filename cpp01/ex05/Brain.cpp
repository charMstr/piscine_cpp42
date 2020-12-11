/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:06:36 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 14:07:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream> //for std::stringstream 
#include <stdint.h>

Brain::Brain(void)
{
	_greyMatterQuantity = 20;
	_size = 20;
	return ;
}

Brain::~Brain(void)
{
	return ;
}

std::string	
Brain::identify(void) const
{
	/* lowercase version...
	** std::stringstream ss;
	** ss << this;
	** return (ss.str());
	*/
	std::stringstream ss;

	ss << "0x" << std::uppercase << std::hex << uintptr_t(this);
	return (ss.str());
}
