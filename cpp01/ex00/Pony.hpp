/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:24:03 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 04:50:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
#include <string>

class Pony
{
	public:
		Pony(void);
		Pony(std::string name, std::string color, std::string food, \
				std::string speed);
		~Pony(void);

		void eat(void);
		void run(void);
		void introduceSelf(void);	
		std::string getName(void);
		std::string getSpeed(void);
		std::string getFavoriteFood(void);
		std::string getColor(void);

	private:
		std::string _name;
		std::string _favoriteFood;
		std::string _color;
		std::string _maxSpeed;
};

#endif
