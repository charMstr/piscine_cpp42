/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 03:40:49 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/09 22:21:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>
# include <iostream>

class Contact
{

public:
	Contact(void);
	~Contact(void);

	void		setFirstName(std::string s);
	std::string getFirstName(void) const;
	void		setLastName(std::string s);
	std::string getLastName(void) const;
	void		setNickName(std::string s);
	std::string getNickName(void) const;
	void		setLogin(std::string s);
	std::string getLogin(void) const;
	void		setPostalAdress(std::string s);
	std::string getPostalAdress(void) const;
	void		setEmailAddress(std::string s);
	std::string getEmailAddress(void) const;
	void		setPhoneNumber(std::string s);
	std::string getPhoneNumber(void) const;
	void		setBirthdayDate(std::string s);
	std::string getBirthdayDate(void) const;
	void		setFavoriteMeal(std::string s);
	std::string getFavoriteMeal(void) const;
	void		setUnderwearColor(std::string s);
	std::string getUnderwearColor(void) const;
	void		setDarkestSecret(std::string s);
	std::string getDarkestSecret(void) const;

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;
};

#endif
