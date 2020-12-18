/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 08:04:13 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 09:33:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
T const & min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template< typename T >
T const & max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
