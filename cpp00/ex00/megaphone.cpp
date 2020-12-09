/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:13:35 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/09 02:31:54 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::string input;
	size_t i;
	size_t len;

	i = 0;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<  std::endl;
		return (0);
	}
	while (++i < (size_t)argc)
		input.append(argv[i]);
	i = 0;
	len = input.length();
	while (i < len)
	{
		input[i] = toupper(input[i]);
		i++; 
	}
	std::cout << input <<  std::endl;
	return (0);
}
