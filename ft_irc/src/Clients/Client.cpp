/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:26:28 by yassine           #+#    #+#             */
/*   Updated: 2024/02/18 12:43:30 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/irc.hpp"


Client::Client() : _nickname("default")
{
}

Client::Client(const Client &src) : _nickname(src._nickname)
{
	*this = src;
}

Client::~Client()
{
}

Client &Client::operator=(const Client &rhs)
{
	if (this != &rhs)
		_nickname = rhs._nickname;
	return *this;
}

std::string Client::getNickname() const
{
	return _nickname;
}

void Client::setNickname(std::string nickname)
{
	_nickname = nickname;
}

bool Client::isNicknameValid(const std::string& nickname) const 
{
    int len = nickname.length();
    if (len >= 9) {
        std::cout << "The nickname is too long" << std::endl;
        return false;
    } 
	else {
        std::cout << "The nickname is good" << std::endl;
        return true;
    }
}

int main()
{
	Client client;
	client = Client();
	std::cout << "Client created" << std::endl;
	std::cout << "Client nickname: " << client.getNickname() << std::endl;
	// Check Limits
	std::string test = "Yassine";
	client.isNicknameValid(test);
	std::cout << "Length of the nickname: " << client.getNickname().length() << std::endl;

	return 0;
}