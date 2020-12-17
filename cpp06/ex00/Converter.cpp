/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 06:55:00 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/17 19:02:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <exception>	//for exception handling
#include <iomanip>  //for std::setprecision
#include <math.h> //for std::fmod
#include <sstream> //for the stringstream.
#include <limits> //for numeric_limits

Converter::Converter(std::string const &input) :
	_charPossible(false),
	_charDisplayable(false),
	_intPossible(false),
	_precision(1),
	_floatPossible(false),
	_doublePossible(false),
	_input(input)
{
	//trim the leading and trailing whitespaces except in the case we have only
	//one unique char, so it can remain a whitespace.
	if (_input.length() != 1)
		trimWhitespaces();	

	//here we make sure it is not just a random string.
	if (!isItANumber())
	{
		if (_input.length() == 1) //we know we can use the char.
		{
			_c = _input[0];
			resolveFromChar();
		}
		return ;
	}

	// and now we now we have a valid string either an int, a float or a double
	getType();	//get the type in _type.
	getPrecision();
	if (_type == INT)	
		resolveFromInt();	
	if (_type == FLOAT)
		resolveFromFloat();
	if (_type == DOUBLE)
		resolveFromDouble();
}

Converter::~Converter(void)
{
	return ;
}

Converter::Converter(Converter const &src)
{
	*this = src;
	return ;
}

Converter	&
Converter::operator=(Converter const &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		_charPossible = rhs._charPossible;
		_charDisplayable = rhs._charDisplayable;
		_c = rhs._c;
		_intPossible = rhs._intPossible;
		_i = rhs._i;
		_floatPossible = rhs._floatPossible;
		_f = rhs._f;
		_doublePossible = rhs._doublePossible;
		_l = rhs._l;
		_input = rhs._input;
	}
	return *this;
}

std::ostream	&
operator<<(std::ostream &o, Converter const &rhs)
{
	return rhs.Serialize(o);
}

std::ostream	&
Converter::Serialize(std::ostream &o) const
{
	//char
	o << "char: ";
	if (_charPossible)
	{
		if (_charDisplayable)
			o << "'" << _c << "'" << std::endl;
		else
			o << "Non displayable" << std::endl;
	}
	else
		o << "impossible" << std::endl;
	//int
	o << "int: ";
	if (_intPossible)
		o << _i << std::endl;
	else
		o << "impossible" << std::endl;
	//set the fixed point value and precision from now.
	o << std::fixed << std::setprecision(_precision);
	//float
	o << "float: ";
	if (_floatPossible)
		o << _f << "f" << std::endl;
	else
	{
		if (!_input.compare("+inf"))
			o << "+inf" << std::endl;
		else if (!_input.compare("-inf"))
			o << "-inf" << std::endl;
		else
			o << "nanf" << std::endl;
	}
	//double
	o << "double: ";
	if (_doublePossible)
		o << _l << std::endl;
	else
	{
		if (!_input.compare("+inf"))
				o << "+inf" << std::endl;
		else if (!_input.compare("-inf"))
			o << "-inf" << std::endl;
		else 
			o << "nan" << std::endl;
	}
	return o;
}

/*
** note:	this function will remove the external whitespaces to the string.
*/
void
Converter::trimWhitespaces(void)
{
	int firstNonWhistace = _input.find_first_not_of(" \n\r\t");
	if (firstNonWhistace > 0) //-1 if string was empty
		_input = _input.substr(_input.find_first_not_of(" \n\r\t"));//left trim
	_input.erase(_input.find_last_not_of(" \n\r\t")+1); //rigth trim 	
}

/*
** This function will try to identify if the string is a possible
** representation of a number.
**
** note:	- if there is more than one dot, we consider it to be a random
** 				string
** 			- it can start by a '+' or '-' signs.
** 			- it can have a char at the end, it can be either a dot, a 'f'
** 			- we dont try to look for "nan", "nanf" etc at this stage.
**
** return:	0, it is jsut a random string
** 			1, it is a representaion of a number.
*/

int	
Converter::isItANumber(void) const
{
	bool	metADot = false;
	bool	metADigit = false;

	if (!_input.length())
		return (0); //empty string case.
	for (size_t i = 0; i < _input.length() ; i++)
	{
		if (i == 0 && (_input[0] == '+' || _input[0] == '-'))
			continue;
		if (_input[i] == '.')
		{
			if (metADot)
				return (0); //we met two dots, so not a number.
			metADot = true;
			continue;
		}
		if (metADigit && _input[i] == 'f' && i + 1 ==  _input.length())
			return (1); //we can finish with a f.
		if (_input[i] > 48 + 9 || _input[i] < 48)
			return (0); //we cannot have something else than a digit at last.
		else
			metADigit = true;
	}
	if (!metADigit) //exclude all the shitty cases like "+." or "." or ".f"...
		return (0);
	return (1);
}

/*
** note:	We call this function when we detected that the initial type is a
** 			char.
*/

void
Converter::resolveFromChar(void)
{
	_charPossible = true;
	if (_c > 31 && _c < 127)
		_charDisplayable = true;
	_intPossible = true;
	_i = static_cast<int>(_c); 
	_doublePossible = true;
	_l = static_cast<double>(_c);
	_floatPossible = true;
	_f = static_cast<float>(_c); //implicit cast ok here...
}

/*
** note:	We get here only if we know the string represent a number in a
** 			valid way.
** 			We extract the type.
*/

void	
Converter::getType(void)
{
	std::size_t found = _input.find("f");
	if (found != std::string::npos) //we know we had a float
	{
		_type = FLOAT;
		_input.erase(found); //remove the trailing f.
		return ;
	}
	found = _input.find(".");
	if (found == std::string::npos) //we know we had an int.
	{
		_type = INT;
		return ;
	}
	_type = DOUBLE;
}

/*
** note:	We get here only if we know the string represent a number in a
** 			valid way.
**
** note:	If there is no dot, we keep the basic precision to be 1. (example
** 			from the subject).
*/

void
Converter::getPrecision(void)
{
	if (_type != DOUBLE && _type != FLOAT)
		return ;
	int dot_index = _input.find_first_of(".");
	if (dot_index >= 0) //we might increase the _precision
	{
		std::string tmp = _input.substr(dot_index + 1);
		if (tmp.length() > 1)
			_precision = tmp.length();
	}
}

void
Converter::resolveFromInt(void)
{
	std::stringstream ss1;
	ss1 << _input;
	ss1 >> _i;
	if (ss1.fail()) //to int failed. but we still can try double, then floats.
	{
		std::stringstream ss2;
		ss2 << _input;	
		ss2 >> _l;
		if (ss2.fail())
			return ; //no conversion was possible.
		_doublePossible = true;
		std::stringstream ss3;
		ss3 << _input;	
		ss3 >> _f;
		if (ss3.fail())
			return ;
		_floatPossible = true;
		return ;
	}
	//get here if the conversion was ok.
	_intPossible = true;
	_l = static_cast<double>(_i); //implicit promotion ok...
	_doublePossible = true;
	_f = static_cast<float>(_i); //implicit promotion ok...
	_floatPossible = true;
	if (_i >= std::numeric_limits<char>::min() \
			&& _i <= std::numeric_limits<char>::max())
	{
		_charPossible = true;
		_c = static_cast<char>(_i);
		if (_i > 31 && _i < 127)
			_charDisplayable = true;
	}
}

void
Converter::resolveFromFloat()
{
	std::stringstream ss1;
	ss1 << _input;
	ss1 >> _f;
	if (ss1.fail()) //if might still fit into a double.
	{
		std::stringstream ss2;
		ss2 << _input;	
		ss2 >> _l;
		if (ss2.fail())
			return ; //no conversion was possible.
		_doublePossible = true;
		return ;
	}
	_floatPossible = true;
	_doublePossible = true;
	_l = static_cast<double>(_f);	//implicit conversion would be ok.
	if (0.0 == fmod(_f, 1.0)) 		//if _f is an "integer".
	{
		if (_f >= static_cast<float>(std::numeric_limits<int>::min()) \
				&& _f <= static_cast<float>(std::numeric_limits<int>::max()))
		{
			_i = static_cast<int>(_f);
			_intPossible = true;
		}
		if (_f >= static_cast<char>(std::numeric_limits<char>::min()) \
				&& _f <= static_cast<char>(std::numeric_limits<char>::max()))
		{
			_charPossible = true;
			_c = static_cast<char>(_f);
			if (_c > 31 && _c < 127)
				_charDisplayable = true;
		}
	}
}

void
Converter::resolveFromDouble(void)
{
	std::stringstream ss1;
	ss1 << _input;
	ss1 >> _l;
	if (ss1.fail())
		return ;
	_doublePossible = true;
	if (fabs(_l) <= static_cast<double>(std::numeric_limits<float>::max()))
	{
		_f = static_cast<float>(_l);
		_floatPossible = true;
	}
	if (0.0 == fmod(_l, 1.0)) //if _l is an "integer".
	{
		if (_l >= static_cast<double>(std::numeric_limits<int>::min()) \
				&& _l <= static_cast<double>(std::numeric_limits<int>::max()))
		{
			_i = static_cast<int>(_l);
			_intPossible = true;
		}
		if (_l >= static_cast<double>(std::numeric_limits<char>::min()) \
				&& _l <= static_cast<double>(std::numeric_limits<char>::max()))
		{
			_c = static_cast<char>(_l);
			_charPossible = true;
			if (_c > 31 && _c < 127)
				_charDisplayable = true;
		}
	}
}
