/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 04:11:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 05:09:38 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
	public:
		Form(std::string const &name = "\"default_form_name\"", \
			int gradeToSign = 1, int gradeToExecute = 150);
virtual	~Form(void);
		Form(Form const &src);
		Form &	operator=(Form const &rhs);

		int					checkGradeToSign(int grade) const;
		int					checkGradeToExecute(int grade, int gradeToSign) const;

		std::string const &	getName(void) const;
		int					getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void 				beSigned(Bureaucrat const &who);
	protected:

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int	const			_gradeToExecute;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
