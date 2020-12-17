/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 06:48:10 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/17 14:55:44 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"
#include <exception>
//remove me
#include <limits>  //

void	display_usage(void)
{
	std::cout << "ERROR: usage: ./convert + 1arg" << std::endl;
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	if (argc < 2 || argc > 2)
	{
		display_usage();
		return (0);
	}
	Converter Conv(argv[1]);
	std::cout << Conv << std::endl;
	return (0);
}
