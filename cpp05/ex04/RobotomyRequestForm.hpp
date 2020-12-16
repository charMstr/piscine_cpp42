/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:31:52 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 09:35:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string const &target = "\"default_robot_target\"");
virtual	~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const &rhs);

		//function that is pur virtual in the parent class:
		std::string			getTarget(void) const;
		virtual	void		actionOnTarget(void) const;

		//overload of the serialized func from parent
		virtual std::ostream & Serialize(std::ostream &o) const;
	protected:

	private:
		std::string		_target;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
