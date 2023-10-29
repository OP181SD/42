/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:36:52 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/24 13:50:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::ShowInterface(void)
{
	std::cout << "===== Phone Book Interface =====" << std::endl;
	std::cout << "1. ADD - Add a new contact" << std::endl;
	std::cout << "2. SEARCH - Search for a contact" << std::endl;
	std::cout << "3. EXIT - Exit the phone book" << std::endl;
	std::cout << "===============================" << std::endl;
}

void PhoneBook::AddContacts()
{

	if (index_contact < 8)
	{
		contacts[index_contact].ContactsInfo();
		index_contact++;
	}
	else
	{
		if (!contacts[index_contact % 8].IsEmpty())
		{
			contacts[index_contact % 8].ContactsInfo();
		}
	}
}

int PhoneBook::IsEndOfFile()
{
	if (std::cin.eof())
	{
		std::cout << "End of input. Exiting the PhoneBook.\n";
		return (1);
	}
	return (0);
}

void PhoneBook::SearchContacts()
{
	if (!(index_contact))
	{
		std::cout << "Empty Contact Arbored." << std::endl;
		return ;
	}
	std::cout << "      *******************" << std::endl;
	std::cout << "            SEARCH       " << std::endl;
	std::cout << "      *******************" << std::endl;
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "FirstName";
	std::cout << "|";
	std::cout << std::setw(10) << "Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < index_contact; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (contacts[i].GetFirstName().length() > 10)
		{
			std::cout << std::setw(10) << contacts[i].GetFirstName().substr(0,
					9) + "."
						<< "|";
		}
		else
		{
			std::cout << std::setw(10) << contacts[i].GetFirstName() << "|";
		}
		if (contacts[i].GetName().length() > 10)
		{
			std::cout << std::setw(10) << contacts[i].GetName().substr(0, 9)
				+ "."
						<< "|";
		}
		else
		{
			std::cout << std::setw(10) << contacts[i].GetName() << "|";
		}
		if (contacts[i].GetNickName().length() > 10)
		{
			std::cout << std::setw(10) << contacts[i].GetNickName().substr(0, 9)
				+ "." << std::endl;
		}
		else
			std::cout << std::setw(10) << contacts[i].GetNickName() << std::endl;
	}
	AskUserForIndex();
}

int PhoneBook::AskUserForIndex()
{
	int		choice;
	Contact	selectedContact;

	std::cout << "Please enter the index you want to see the details of the contact: " << std::endl;
	while (true)
	{
		if (!(std::cin >> choice))
		{
			if (IsEndOfFile())
				return (1);
			else
			{
				std::cout << "Invalid input. Please enter a valid index." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
								'\n');
			}
		}
		else if (choice >= 0 && choice < index_contact)
		{
			selectedContact = contacts[choice];
			std::cout << "Contact Details:" << std::endl;
			std::cout << "First Name: " << selectedContact.GetFirstName() << std::endl;
			std::cout << "Name: " << selectedContact.GetName() << std::endl;
			std::cout << "Nickname: " << selectedContact.GetNickName() << std::endl;
			std::cout << "PhoneNumber: " << selectedContact.GetPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << selectedContact.GetDarkestSecret() << std::endl;
			return (choice);
		}
		else
		{
			std::cout << "Invalid index. Please enter a valid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void PhoneBook::Interface()
{
	std::string choice;
	std::cout << "Welcome, please make a choice inside the PhoneBook:\n";
	while (true)
	{
		ShowInterface();
		if (IsEndOfFile())
			break ;
		std::cin >> choice;
		if (IsEndOfFile())
			break ;
		else if (choice == "ADD")
			AddContacts();
		else if (choice == "SEARCH")
			SearchContacts();
		else if (choice == "EXIT")
		{
			std::cout << "Exiting The PhoneBook GoodBye." << std::endl;
			return ;
		}
		else
		{
			std::cout << "Invalid input please enter a valid input";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
	}
}

int	main(void)
{
	PhoneBook	f;

	f.Interface();
	return (0);
}
