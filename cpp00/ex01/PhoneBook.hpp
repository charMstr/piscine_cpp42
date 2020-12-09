/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:53:44 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 00:15:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
# define SIZE_BOOK 2

class PhoneBook
{
	public:
		PhoneBook(int size);
		~PhoneBook(void);

		void		setContact(Contact &contact);
		void		getContact(int index) const;
		int			getSize(void) const;
		void		getContactList(void) const;

	private:
		Contact _Book[SIZE_BOOK];
		int		_index;
		int		_capacity;
		int		_isFull;

		std::string	stringResize(std::string &s) const;
};

#endif
