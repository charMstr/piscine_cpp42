/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:54:11 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/09 07:14:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include "../includes/Contacts.hpp"
#include <string>

//constructor
//initialise fullNess to 1
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
	
	who = this->_Book[index - 1];
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
