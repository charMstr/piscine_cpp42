/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:54 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 04:59:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name = "\"default\"", int grade = 150);
virtual	~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &	operator=(Bureaucrat const &rhs);

		int 				checkGrade(int grade);

		std::string const &	getName(void) const;
		int					getGrade(void) const;
		void				incGrade(void);
		void				decGrade(void);

		void				signForm(Form &form) const;
	protected:

	private:
		std::string	const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
