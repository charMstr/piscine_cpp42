/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 08:53:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*
int main(void)
{
	Fixed b(255);
	Fixed f(43.34f);

	std::cout << b.getRawBits() << std::endl;
	std::cout << b.toInt() << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;

	std::cout << f.getRawBits() << std::endl;
	std::cout << f.toInt() << std::endl;
	std::cout << f.toFloat() << std::endl;
	std::cout << f << std::endl;
	return 0;
}
*/
int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
