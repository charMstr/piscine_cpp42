/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:46 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 12:31:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int int_input);
		Fixed(const float int_input);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &	operator=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		//six comparison operators
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		//4 arithmetic operators
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		//pre-inc, post-inc, pre-dec, post-dec
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		//non member functions min and max
		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static Fixed	&max(Fixed &ref1, Fixed &ref2);

		static Fixed const &min(const Fixed &ref1, const Fixed &ref2);
		static Fixed const &max(const Fixed &ref1, const Fixed &ref2);
	protected:

	private:
		int					_fixedPointValue;
		static const int	_bitsNbr;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
