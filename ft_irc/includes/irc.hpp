/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:40:42 by yassine           #+#    #+#             */
/*   Updated: 2024/02/18 12:43:12 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools.hpp"
#include "containers.hpp"
#include "base.hpp"


class Client
{
private:
	std::string _nickname;
public:
	// Canonical form
	Client();
	Client(const Client &src);
	Client &operator=(const Client &rhs);
	~Client();
	// Getters
	std::string getNickname() const;
	// Setters
	void setNickname(std::string nickname);
	// Member functions

	// isNickNameValid checks if the nickname has a valid format of  9 characters .
	bool isNicknameValid(const std::string & nickname) const;
};