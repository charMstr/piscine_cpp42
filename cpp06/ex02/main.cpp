/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:24:33 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/17 17:03:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include "B.hpp"

Base * generate(void)
{
    srand( (unsigned) time(NULL) * getpid());
	int choice;

	choice =  rand() % 3;
	if (choice == 0)
	{
		std::cout << "generated a pointer to A" << std::endl;
		return (new A);
	}
	else if (choice == 1)
	{
		std::cout << "generated a pointer to B" << std::endl;
		return (new B);
	}
	std::cout << "generated a pointer to C" << std::endl;
	return (new C);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "WTF!?" << std::endl;
}

void identify_from_reference( Base & p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception const &e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception const &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception const &e){}
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	Base *unknown = generate();	
	
	identify_from_pointer(unknown);

	identify_from_reference(*unknown);

	delete unknown;
	return (0);
}
