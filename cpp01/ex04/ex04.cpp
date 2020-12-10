/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:26:09 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 08:28:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::string hi = "HI THIS IS BRAIN";
	std::string *ptr;
	std::string &ref = hi;

	ptr = &hi;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}
