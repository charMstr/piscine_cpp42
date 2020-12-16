/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:14:43 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 12:00:56 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
class Form;
class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;

class Intern
{
	public:
		typedef Form * (Intern::*generator)(std::string const &target) const;

		Intern(void);
virtual	~Intern(void);
		Intern(Intern const &src);
		Intern &	operator=(Intern const &rhs);

	//function to serialize my output from the << overload
		//virtual std::ostream & Serialize(std::ostream &o) const;

		Form *makeForm(std::string const &formName = "\"default_\"", \
				std::string const &target = "\"default_target\"") const;

		Form *createRobotomyRequestForm(std::string const &target) const;
		Form *createPresidentialPardonForm(std::string const &target) const;
		Form *createShrubberyCreationForm(std::string const &target) const;

		//typedef for my generic functions
	protected:

	private:
		std::string		_knownForms[3];
		int				_nbKnownForms;
		generator		_funcArray[3];
		
};

//std::ostream	&operator<<(std::ostream &o, Intern const &rhs);

#endif
