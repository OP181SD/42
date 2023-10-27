/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:22:00 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 19:05:40 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	detecte_quote(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	else if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}
