/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 12:29:18 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
/*
int main(void)
{
	Fixed b(4);
	Fixed c(4);

	std::cout << std::endl << "A) post increments" << std::endl;

	Fixed a(5);
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl << "B) pre increments" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl << "C) equality" << std::endl;
	if (c == b)
		std::cout << "both are equal" << std::endl;

	std::cout << std::endl << "D) superiority" << std::endl;
	if (a > b)
		std::cout << "OK a is higher than b" << std::endl;
	if (a < b)
		std::cout << "OK a is lower than b" << std::endl;

	std::cout << std::endl << "E) addition" << std::endl;
	std::cout << c + b << std::endl;
	std::cout << (c + b).toInt() << std::endl;


	std::cout << std::endl << "E) checking the small increment" << std::endl;
	Fixed J(42.0f);
	std::cout << J.toFloat() << std::endl;
	++J;
	std::cout << J.toFloat() << std::endl;


	std::cout << std::endl << "E) min" << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	c--;
	std::cout << "printing the min:" << Fixed::min(b, c) << std::endl;

	return 0;
}
*/
