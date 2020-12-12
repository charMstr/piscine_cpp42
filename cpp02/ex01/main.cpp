/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:46:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/12 08:39:50 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

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
