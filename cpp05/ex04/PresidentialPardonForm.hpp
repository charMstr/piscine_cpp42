/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:41:07 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:43:18 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string const &target = "\"default_robot_target\"");
virtual	~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const &rhs);

		//function that is pur virtual in the parent class:
		std::string			getTarget(void) const;
		virtual	void		actionOnTarget(void) const;

		//overload of the serialized func from parent
		virtual std::ostream & Serialize(std::ostream &o) const;
	protected:

	private:
		std::string		_target;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
