/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:46 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 08:29:18 by charmstr         ###   ########.fr       */
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
	protected:

	private:
		int					_fixedPointValue;
		static const int	_bitsNbr;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
