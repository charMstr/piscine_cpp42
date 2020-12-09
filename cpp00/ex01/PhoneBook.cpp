/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:54:11 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/10 00:14:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"
#include <string>
#include <iomanip>

//constructor
PhoneBook::PhoneBook(int size) :
		_index(0),
		_capacity(size),
		_isFull(0)
{
	return ;
}

//destructor
PhoneBook::~PhoneBook(void)
{
	return ;
}

//display the list of contacts
void
PhoneBook::getContactList(void) const
{
	std::string line;
	std::string item;
	int			num;
	
	line.append(10 * 4 + 5, '-');
	std::cout << line << std::endl;
	std::cout << "|" << std::setw(11) << "index |";
	std::cout << std::setw(11) << "first name|";
	std::cout << std::setw(11) << "last name |";
	std::cout << std::setw(11) << "nickname |" << std::endl;
	std::cout << line << std::endl;
	num = 0;
	while (num < this->getSize())
	{
		std::cout << "|" << std::setw(6) << num + 1 << "    ";
		item = (this->_Book[num].getFirstName());
		std::cout << "|" << std::setw(10) << this->stringResize(item);
		item = (this->_Book[num].getLastName());
		std::cout << "|" << std::setw(10) << this->stringResize(item);
		item = (this->_Book[num].getLogin());
		std::cout << "|" << std::setw(10) << this->stringResize(item);
		std::cout << "|" << std::endl;
		std::cout << line << std::endl;
		num++;
	}
}

std::string
PhoneBook::stringResize(std::string &s) const
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	else
		return (s);
}

//add a contact in the PhoneBook
void
PhoneBook::setContact(Contact &contact)
{
	if (this->_index >= this->_capacity)
	{ 
		std::cout << "\033[31mWarning: the PhoneBook is full, overiding the "\
			"oldest contact\033[m" << std::endl;
		this->_isFull = 1;
		this->_index = 0;
	}
	this->_Book[this->_index].setFirstName(contact.getFirstName());
	this->_Book[this->_index].setLastName(contact.getLastName());
	this->_Book[this->_index].setNickName(contact.getNickName());
	this->_Book[this->_index].setLogin(contact.getLogin());
	this->_Book[this->_index].setPostalAdress(contact.getPostalAdress());
	this->_Book[this->_index].setEmailAddress(contact.getEmailAddress());
	this->_Book[this->_index].setPhoneNumber(contact.getPhoneNumber());
	this->_Book[this->_index].setBirthdayDate(contact.getBirthdayDate());
	this->_Book[this->_index].setFavoriteMeal(contact.getFavoriteMeal());
	this->_Book[this->_index].setUnderwearColor(contact.getUnderwearColor());
	this->_Book[this->_index].setDarkestSecret(contact.getDarkestSecret());
	this->_index = this->_index + 1;
}

//returns how many contacts we have in the PhoneBook sa far
int
PhoneBook::getSize( void ) const
{
	if (this->_isFull)
		return (this->_capacity);
	return (this->_index);
}

//get the information regarding a contact
void
PhoneBook::getContact(int index) const
{
	std::string line;
	std::string item;
	Contact who;
	
	if (index > this->_capacity || index < 0)
		return ;
	who = this->_Book[index];
	line.append(80, '-');
	std::cout << line << std::endl;
	item = who.getFirstName();
	std::cout << "first name: " << item << std::endl;
	item = who.getLastName();
	std::cout << "last name: " << item << std::endl;
	item = who.getNickName();
	std::cout << "nickname: " << item << std::endl;
	item = who.getLogin();
	std::cout << "login: " << item << std::endl;
	item = who.getPostalAdress();
	std::cout << "postal address: " << item << std::endl;
	item = who.getEmailAddress();
	std::cout << "email address: " << item << std::endl;
	item = who.getPhoneNumber();
	std::cout << "phone number: " << item << std::endl;
	item = who.getBirthdayDate();
	std::cout << "birthday: " << item << std::endl;
	item = who.getFavoriteMeal();
	std::cout << "favorite meal: " << item << std::endl;
	item = who.getUnderwearColor();
	std::cout << "undewear color: " << item << std::endl;
	item = who.getDarkestSecret();
	std::cout << "darkest secret: " << item << std::endl;
	std::cout << line << std::endl;
}
