/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 06:55:00 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/17 14:31:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class Converter
{
	public:
		Converter(std::string const &input = "\"default\"");
virtual	~Converter(void);
		Converter(Converter const &src);
		Converter &	operator=(Converter const &rhs);

	//function to serialize my output from the << overload
		std::ostream & Serialize(std::ostream &o) const;

	protected:
		void	ConvertToChar(void);
		
		typedef enum	e_my_type
		{
			CHAR, INT, FLOAT, DOUBLE
		}				t_my_type;

	private:
		t_my_type	_type;
		//char
		bool		_charPossible;
		bool		_charDisplayable;
		char		_c;

		//int
		bool		_intPossible;
		int			_i;
	
		int			_precision; //default to one
		//float
		bool		_floatPossible;
		float		_f;

		//double
		bool		_doublePossible;
		double		_l;	


		std::string	_input;

		void	trimWhitespaces(void);
		int		isItANumber(void) const;
		void	getType(void);
		void	getPrecision(void);
		void	resolveFromChar(void);
		void	resolveFromInt(void);
		void	resolveFromFloat(void);
		void	resolveFromDouble(void);
};

std::ostream	&operator<<(std::ostream &o, Converter const &rhs);

#endif
