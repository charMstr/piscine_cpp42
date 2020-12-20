/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 13:34:04 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/20 18:40:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>

class Span
{
	public:
		Span(unsigned int N = 42);
virtual	~Span(void);
		Span(Span const &src);
		Span &	operator=(Span const &rhs);

		void	addNumber(int i);
		int		longestSpan() const;
		int		shortestSpan() const;
		int		getfirstForPeer() const;
		int		getLastForPeer() const;
	protected:

	private:
		unsigned int N;
		unsigned int _total_entries;
		std::set<int> _set_of_ints;	
};

#endif
