/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:37:56 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/24 13:23:23 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>

#pragma once

class Contact
{
  public:
	void ContactsInfo(void);
	int IsEmpty();
	std::string GetFirstName();
	std::string GetName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
	Contact();
	~Contact();

  private:
	std::string _firstname;
	std::string _name;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;
	void GetContactsInfo(void);
};
