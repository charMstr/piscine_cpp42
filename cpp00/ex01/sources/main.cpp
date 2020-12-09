/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 02:38:07 by charmstr          #+#    #+#             */
/*   Updated: 2020/12/09 07:45:42 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Contacts.hpp"
#include "../includes/PhoneBook.hpp"

int	get_user_input(std::string question, std::string *ptr)
{
	std::cout << question << std::endl;
	std::getline(std::cin, *ptr);
	if (std::cin.eof())
		return (0);
	return (1);
}

int say_good_bye(void)
{
	std::cout << "😼 good bye!" << std::endl;
	return (0);
}

/*
** note:	The is full variable is set to one if we already added SIZE_BOOK
**			contacts.
*/

int search_contact(PhoneBook *Phonebook)
{
	std::string input;
	int			choice;

	while (1)
	{ 
		std::cout << std::endl << "lets SEARCH a contact! 🔎" << std::endl;
		//TODO
		//print here the contact menu
		/!\//check files names in subject!!!
		if (!get_user_input("which contact number do you want to check out", &input))
			return (0);
		//check the input is number only:
		if (!(input.find_first_not_of("0123456789") == std::string::npos))
			continue ;
		choice = std::stoi(input, NULL, 10);
		//check the input number is within range:
		if (choice > Phonebook->getSize() || choice < 1)
			continue ;
		break ;
	}
	Phonebook->getContact(choice);
	return (1);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	std::string	input;
	PhoneBook	Phonebook = PhoneBook(SIZE_BOOK);
	Contact		New;

	std::cout << "😼 WELCOME TO THE MAGIC PHONEBOOK !" << std::endl;
	while (1)
	{
		std::cout << std::endl;
		if (!get_user_input("please type in an action: ADD | SEARCH | EXIT", &input))
			return (say_good_bye());
		else if (!input.compare("EXIT"))
			return (say_good_bye());
		else if (!input.compare("ADD"))
		{ 	
			std::cout << std::endl << "lets ADD a contact! ☎️ " << std::endl;
			if (!get_user_input("first name?", &input))
				return (say_good_bye());
			New.setFirstName(input);
			if (!get_user_input("Last name?", &input))
				return (0);
			New.setLastName(input);
			if (!get_user_input("Nick name?", &input))
				return (0);
			New.setNickName(input);
			if (!get_user_input("Login?", &input))
				return (0);
			New.setLogin(input);
			/*
			if (!get_user_input("postal address?", &input))
				return (0);
			New.setPostalAdress(input);
			if (!get_user_input("email address?", &input))
				return (0);
			New.setEmailAddress(input);
			if (!get_user_input("phone number?", &input))
				return (0);
			New.setPhoneNumber(input);
			if (!get_user_input("birth date?", &input))
				return (0);
			New.setBirthdayDate(input);
			if (!get_user_input("favorite meal?", &input))
				return (0);
			New.setFavoriteMeal(input);
			if (!get_user_input("underwear color?", &input))
				return (0);
			New.setUnderwearColor(input);
			if (!get_user_input("darkest secret?", &input))
				return (0);
			New.setDarkestSecret(input);
			*/
			Phonebook.setContact(New);
		}
		else if (!input.compare("SEARCH"))
		{
			if (!search_contact(&Phonebook))
				return (say_good_bye());
		}
	}
	return (0);
}
