/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:41:38 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/21 00:03:16 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP

//#include <iostream>
#include <iterator>
# include <stack>

/* ****************************************************************************
** HERE definition of template class: MutantStack
******************************************************************************/

template < typename T >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename MutantStack<T>::container_type::iterator iterator;
        typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
        typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack<T>(void);
virtual	~MutantStack<T>(void);
		MutantStack<T>(MutantStack<T> const &src);
		MutantStack &	operator=(MutantStack const &rhs);

		iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

	protected:

	private:
};

/* ****************************************************************************
** HERE (1/2) source code for template class: MutantStack
******************************************************************************/

template < typename T >
MutantStack<T>::MutantStack(void) : std::stack<T>() { }

template < typename T >
MutantStack<T>::~MutantStack(void) { }

template < typename T >
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
	*this = src;
}

template < typename T >
MutantStack<T> &
MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	return *this;
}

/* ****************************************************************************
** HERE (2/2) source code for template class: MutantStack
******************************************************************************/

template < typename T >
typename MutantStack<T>::iterator
MutantStack<T>::begin()
{
	return (MutantStack<T>::c.begin());
}

template < typename T >
typename MutantStack<T>::const_iterator
MutantStack<T>::begin() const
{
	return (MutantStack<T>::c.begin());
}

template < typename T >
typename MutantStack<T>::iterator
MutantStack<T>::end() { return (MutantStack<T>::c.end()); }

template < typename T >
typename MutantStack<T>::const_iterator
MutantStack<T>::end() const { return (MutantStack<T>::c.end()); }

template< typename T >
typename MutantStack<T>::reverse_iterator
MutantStack<T>::rbegin() { return (MutantStack<T>::c.rbegin()); }

template< typename T >
typename MutantStack<T>::const_reverse_iterator
MutantStack<T>::rbegin() const { return (MutantStack<T>::c.rbegin()); }

template< typename T >
typename MutantStack<T>::reverse_iterator
MutantStack<T>::rend() { return (MutantStack<T>::c.rend()); }

template< typename T >
typename MutantStack<T>::const_reverse_iterator
MutantStack<T>::rend() const { return (MutantStack<T>::c.rend()); }

#endif
