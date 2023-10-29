/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:38:09 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/24 13:50:17 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>

#pragma once

class PhoneBook
{
  public:
	void ShowInterface(void);
	void AddContacts();
	void Interface();
	void SearchContacts();
	int AskUserForIndex();
	int IsEndOfFile();
	PhoneBook();
	~PhoneBook();

  private:
	Contact contacts[8];
	std::string add;
	std::string search;
	std::string exit;
	int index_contact;
};