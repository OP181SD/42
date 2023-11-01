/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:52:54 by yassine           #+#    #+#             */
/*   Updated: 2023/11/01 14:12:32 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
{
  public:
	Harl();
	~Harl();
	void complain(const std::string &level);
  private:
	void Debug(void);
	void Info(void);
	void Warning(void);
	void Error(void);
};