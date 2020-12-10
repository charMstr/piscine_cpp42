/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:24:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 04:56:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	Pony Maurice = Pony("Maurice", "blue", "hay", "25km/h");
	Pony *Jumper = new Pony("Jumper", "red", "apples", "100km/h");

	Maurice.introduceSelf();
	Maurice.run();
	Maurice.eat();

	std::cout << std::endl;

	Jumper->introduceSelf();
	Jumper->run();
	Jumper->eat();
	
	std::cout << std::endl;

//comment out this line and you will see that Jumper's destructor is never
//called.
	delete Jumper;
	return (0);
}
