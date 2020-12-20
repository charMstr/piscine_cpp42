/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 13:34:04 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/20 18:42:17 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

Span::Span(unsigned int N) :
	N(N),
	_total_entries(0)
{
	//std::cout << "\033[33mconstructor called for Span\033[0m" << std::endl;
	return ;
}

Span::~Span(void)
{
	//std::cout << "\033[31m[~]\033[33mdestructor called for Span\033[0m" << std::endl;
	return ;
}

Span::Span(Span const &src)
{
	//std::cout << "\033[33m[COPY]constructor called for Span\033[0m" << std::endl;
	*this = src;
	return ;
}

Span	&
Span::operator=(Span const &rhs)
{
	//std::cout << "\033[33m'=' operator called for Span\033[0m" << std::endl;
	if (this != &rhs)
	{
		N = rhs.N;
		_total_entries = rhs._total_entries;
		_set_of_ints = rhs._set_of_ints;	
	}
	return *this;
}

void
Span::addNumber(int i)
{
	if (_total_entries == N)	
	{
		std::string error_msg("Span: already N elements, cant add: ");
		error_msg += std::to_string(i);
		throw std::out_of_range(error_msg);
	}
	_total_entries++;
	_set_of_ints.insert(i);
}

int	
Span::longestSpan() const
{
	if (_total_entries < 2)
		throw std::domain_error ("Span: need at least 2 values, domain_error");
	return ( *(--_set_of_ints.end()) - *(_set_of_ints.begin()) );
}

/*
** In this function we store the differences in a vector, we know the very
** first index is biased because it does ont contain a difference but the
** actual first value itself. Hence the ++ in the return to avoid the first
** index
*/

int
Span::shortestSpan() const
{
	if (_total_entries < 2)
		throw std::domain_error ("Span: need at least 2 values, domain_error");
	std::vector<int> diff(_total_entries);
	std::adjacent_difference(_set_of_ints.begin(), _set_of_ints.end(), diff.begin());
	return (*std::min_element(++diff.begin(), diff.end()));
}

int
Span::getfirstForPeer() const
{
	//not protected. just fot the proof of concept with a big longest span
	return (*_set_of_ints.begin());
}

int
Span::getLastForPeer() const
{
	//not protected. just fot the proof of concept with a big longest span
	return (*--_set_of_ints.end());
}
