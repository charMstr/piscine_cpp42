/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:38:29 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 13:34:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <iostream>
class Bureaucrat;
class Intern;
class Form;

class OfficeBlock
{
	public:
		OfficeBlock(void);
		OfficeBlock(Intern *intern, Bureaucrat *signator, Bureaucrat *executor);
virtual	~OfficeBlock(void);

	//function to serialize my output from the << overload
		virtual std::ostream & Serialize(std::ostream &o) const;

		void	addInternToBlock(Intern *newbie);
		void	addSignatorToBlock(Bureaucrat *signator);
		void	addExecutorToBlock(Bureaucrat *executor);

		//the only really usefull function
		void 	doBureaucracy(std::string const &formName, \
				std::string const &target);
	protected:

	private:
		Intern		*_intern;
		Bureaucrat	*_signator;
		Bureaucrat	*_executor;
		int			_staffNumber;
		Form		*_createdForm;
};

std::ostream	&operator<<(std::ostream &o, OfficeBlock const &rhs);

#endif
