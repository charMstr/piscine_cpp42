/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 03:47:19 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/09 22:20:44 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contacts.hpp"

//constructor
Contact::Contact( void )
{
	return ;
}

//destructor
Contact::~Contact( void )
{
	return ;
}

void
Contact::setFirstName(std::string s)
{
	this->_first_name = s;
}

std::string
Contact::getFirstName(void) const
{
	return (this->_first_name);
}

void
Contact::setLastName(std::string s)
{
	this->_last_name = s;
}

std::string
Contact::getLastName(void) const
{
	return (this->_last_name);
}

void
Contact::setNickName(std::string s)
{
	this->_nickname = s;
}

std::string
Contact::getNickName(void) const
{
	return (this->_nickname);
}

void
Contact::setLogin(std::string s)
{
	this->_login = s;
}

std::string
Contact::getLogin(void) const
{
	return (this->_login);
}

void
Contact::setPostalAdress(std::string s)
{
	this->_postal_address = s;
}

std::string
Contact::getPostalAdress(void) const
{
	return (this->_postal_address);
}

void
Contact::setEmailAddress(std::string s)
{
	this->_email_address = s;
}

std::string
Contact::getEmailAddress(void) const
{
	return (this->_email_address);
}

void
Contact::setPhoneNumber(std::string s)
{
	this->_phone_number = s;
}

std::string
Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

void
Contact::setBirthdayDate(std::string s)
{
	this->_birthday_date = s;
}

std::string
Contact::getBirthdayDate(void) const
{
	return (this->_birthday_date);
}

void
Contact::setFavoriteMeal(std::string s)
{
	this->_favorite_meal = s;
}

std::string
Contact::getFavoriteMeal(void) const
{
	return (this->_favorite_meal);
}

void
Contact::setUnderwearColor(std::string s)
{
	this->_underwear_color = s;
}

std::string
Contact::getUnderwearColor(void) const
{
	return (this->_underwear_color);
}

void
Contact::setDarkestSecret(std::string s)
{
	this->_darkest_secret = s;
}

std::string
Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}
