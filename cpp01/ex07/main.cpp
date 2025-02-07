/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 07:11:01 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 14:20:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

int charByChar(std::ifstream &ifs, std::string s1, std::string s2, std::ofstream  &ofs);

void display_usage(void)
{
	std::cout << "usage: ./replace filename s1 s2" << std::endl;
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	if (argc != 4)		
	{
		display_usage();
		return (EXIT_FAILURE);
	}
	std::ifstream ifs(argv[1]);	
	std::string output(argv[1]);
	output = output +  "." + "replace";
	char cstr[output.size() + 1];
	strcpy(cstr, output.c_str());
	std::ofstream ofs(cstr);	
	if (!ifs)
	{
		std::cout << "Error: could not open: "<< argv[1]  << std::endl;
		return (EXIT_FAILURE);
	}
	if (!ofs)
	{
		std::cout << "Error: could not open: "<< output << std::endl;
		ifs.close();
		return (EXIT_FAILURE);
	}
	int res = charByChar(ifs, argv[2], argv[3], ofs);
	ifs.close();
	ofs.close();
	return (!res);
}
