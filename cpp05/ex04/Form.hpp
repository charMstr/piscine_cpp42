/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 04:11:28 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/16 08:36:46 by charmstr         ###   ########.fr       */
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
		//making the class abstract here so that we dont have to reimplement
		//the other functions. special, we actually define the destructor still
		//we did it under on the end but good to know...
virtual	~Form(void) = 0;
		Form(Form const &src);
		Form &	operator=(Form const &rhs);

		int					checkGradeToSign(int grade) const;
		int					checkGradeToExecute(int grade) const;

		std::string const &	getName(void) const;
		int					getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		virtual void 		beSigned(Bureaucrat const &who); 
		void				execute(Bureaucrat const &executor) const;
		virtual	void		actionOnTarget(void) const = 0;

		//added func to hace a comon serialized output of form
		virtual std::ostream & Serialize(std::ostream &o) const;
	protected:

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int	const			_gradeToExecute;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
