/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:18:22 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/18 15:42:16 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <ctype.h>
#include <exception>
#include <iostream>

template< typename T >
class Array
{
	public:
	Array<T>(void)
	{
		std::cout << "\033[33mconstructor called\033[0m" << std::endl;
		_array = new T[0]();	//creating an empty array.
		_size = 0;
	}

	Array<T>(unsigned int n)
	{
		std::cout << "\033[33m[size = n] constructor called\033[0m" << std::endl;
		_array = new T[n]();	//creating an array of n elements initialized.
		_size = n;				//note: pointers will be initialized to zero.
	}

	virtual	~Array<T>(void)
	{
		std::cout << "\033[31m[~]\033[33mdestructor called\033[0m" << std::endl;
		delete[] _array;
	}

	Array<T>(Array const &rhs) :
		_array(0)
	{
		std::cout << "\033[33m[COPY] constructor called\033[0m" << std::endl;
		*this = rhs;
	}

	Array &	operator=(Array const &rhs)
	{
		std::cout << "\033[33moperator '=' called\033[0m" << std::endl;
		delete[] _array; //delete any old values
		_size = rhs.size();
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
		return (*this);
	}

	unsigned int size(void) const
	{
		return (_size);
	}

	//function to serialize my output from the << overload
		//virtual std::ostream & Serialize(std::ostream &o) const;

	T &	operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::out_of_range("Array: out of range");
		return (_array[i]);
	}

	protected:

	private:
		T			*_array;
		size_t		_size;
};

//std::ostream	&operator<<(std::ostream &o, Array const &rhs);

#endif
