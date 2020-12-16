/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:31:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 03:34:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

#include <iostream>
# include <exception>

class MyException : public std::exception
{
	public:
		MyException(std::string const &message = \
				"MyException default message");
		virtual	~MyException() throw() {};

		virtual const char * what() const throw();

	protected:
		std::string	_message;

	private:
		
};

//std::ostream	&operator<<(std::ostream &o, MyException const &rhs);

#endif
