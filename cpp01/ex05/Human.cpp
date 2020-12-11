/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:18 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 14:08:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <sstream> //for std::stringstream 
#include <stdint.h>

Human::Human(void)
{
	_name = "default";
	return ;
}

Human::~Human(void)
{
	return ;
}

std::string	
Human::identify(void) const
{
	/* lowercase version...
	** std::stringstream ss;
	** ss << &this->_Brain;
	** return (ss.str());
	*/
	std::stringstream ss;

	ss << "0x" << std::uppercase << std::hex << uintptr_t(&(this->_Brain));
	return (ss.str());
}

const Brain&
Human::getBrain(void) const
{
	return (this->_Brain);
}
