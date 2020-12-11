/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charByChar.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 07:57:46 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/11 09:40:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/*
** return 	1, OK
** 			0, KO something went wrong with ifs.
*/

int charByChar(std::ifstream &ifs, std::string s1, std::string s2, std::ofstream  &ofs)
{
	char c;
	int i_s1;
	char first;

	while ((c = ifs.get()) && ifs.good())
	{
		i_s1 = 0;
		if (c == s1[i_s1])
		{
			i_s1++;
			first = c;
			int start = ifs.tellg();
			while ((c = ifs.get()) && ifs.good() && s1[i_s1] && c == s1[i_s1])
				i_s1++;	
			if (ifs.bad())
				return (0);
			if (!s1[i_s1])
			{
				ofs << s2;		
				ifs.unget();
				if (!ifs.good())
					return (0);	
			}
			else
			{
				ofs << first;
				ifs.seekg(start);	
				if (!ifs.good())
					return (0);	
			}
		}
		else
			ofs << c ;
	}
	if (ifs.bad())
		return (0);
	return (1);
}
