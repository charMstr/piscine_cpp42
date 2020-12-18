/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:17:15 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 11:34:08 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP


# include <cstring>
//#include <iostream>

template< typename T >
void
//iter(T * const &array_ptr, size_t length, void (*f)(T))
iter(T *array_ptr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)	
	{
		f(array_ptr[i]);
	}
}

template< typename T >
void
funcIter(T &i)
{
	if (i > 96  && i < ('z' + 1))
		i  = i - ('a' - 'A');
}

template< typename T >
void
funcIter2(T &i)
{
	if (i != 42)
		i = 0;
}

#endif
