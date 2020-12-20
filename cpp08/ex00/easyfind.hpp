/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:30:47 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/20 13:15:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>

/* only able to use variadic in the c++11, too bad we could have force the
** container to be of type container<int>
template< template < class ... > class T>
typename T<int>::iterator
easyfind(T<int> &container, int number)
{
	return find(container.begin(), container.end(), number);
}
*/

template< class T>
typename T::iterator
easyfind(T &container, int number)
{
	return find(container.begin(), container.end(), number);
}

#endif
