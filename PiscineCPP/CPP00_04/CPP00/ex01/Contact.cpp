/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:37:25 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/24 13:37:16 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _firstname(""), _name(""), _nickname(""), _phonenumber(""),
		_darkestsecret("")
{
}

Contact::~Contact()
{
}

std::string Contact::GetFirstName()
{
	return (_firstname);
}

std::string Contact::GetName()
{
	return (_name);
}

std::string Contact::GetNickName()
{
	return (_nickname);
}

std::string Contact::GetPhoneNumber()
{
	return (_phonenumber);
}

std::string Contact::GetDarkestSecret()
{
	return (_darkestsecret);
}

void Contact::GetContactsInfo()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Contact::IsEmpty(void)
{
	return (_firstname.empty() && _name.empty() && _nickname.empty());
}

void Contact::ContactsInfo()
{
	std::cout << "Enter your First Name: " << std::endl;
	std::cin >> this->_firstname;
	GetContactsInfo();
	std::cout << "Enter your Name: " << std::endl;
	std::cin >> this->_name;
	GetContactsInfo();
	std::cout << "Enter Your NickName: " << std::endl;
	std::cin >> this->_nickname;
	GetContactsInfo();
	std::cout << "Enter your PhoneNumber: " << std::endl;
	std::cin >> this->_phonenumber;
	GetContactsInfo();
	std::cout << "Enter your DarkestSecret: " << std::endl;
	std::cin >> this->_darkestsecret;
	GetContactsInfo();
}