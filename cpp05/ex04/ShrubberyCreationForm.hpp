/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 05:54:44 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:20:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(std::string const &target = "\"default_shrubbery_target\"");
virtual	~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &rhs);

		//function that is pur virtual in the parent class:
		std::string			getTarget(void) const;
		virtual	void		actionOnTarget(void) const;

		//overload of the serialized func from parent
		virtual std::ostream & Serialize(std::ostream &o) const;
	protected:

	private:
		std::string		_target;
		void			_drawTree(std::ostream &o) const;
		
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
