/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:31:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 14:56:32 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "MyException.hpp"
#include <cstring>

MyException::MyException(std::string const &message) :
	_message(message)
{
	return ;
}

//make sure the message is of type char *, old school.
const char *
MyException::what() const throw()
{
	return (_message.c_str());
}
